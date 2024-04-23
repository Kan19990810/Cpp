#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>
#include <memory>
#include <iostream>

using namespace std;

class ThreadPool
{
private:
    struct Pool
    {
        mutex mtx;
        condition_variable con;
        bool is_close;
        queue<function<void()>> taskQueue;
    };
    shared_ptr<Pool> pool_;

public:
    explicit ThreadPool(int threadNum) : pool_(make_shared<Pool>())
    {
        for (int i = 1; i <= threadNum; ++i)
        {
            thread([pool = pool_]
                   {
                unique_lock<mutex> lock(pool -> mtx);
                while (true) {
                    if (!pool -> taskQueue.empty()) {
                        auto task = move(pool -> taskQueue.front());
                        pool -> taskQueue.pop();
                        lock.unlock();
                        task();
                        lock.lock();
                    }
                    else if (pool -> is_close) {
                        break;
                    }
                    else {
                        pool -> con.wait(lock);
                    }

                } })
                .detach();
        }
    }

    ~ThreadPool()
    {
        if (static_cast<bool>(pool_))
        {
            lock_guard<mutex> lock(pool_->mtx);
            pool_->is_close = true;
            pool_->con.notify_all();
        }
    }

    template <typename T>
    void addTask(T &&task)
    {
        lock_guard<mutex> lock(pool_->mtx);
        pool_->taskQueue.push(forward<T> task);
        pool_->con.notify_one();
    }
};