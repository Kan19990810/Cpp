#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

using namespace std;

atomic_flag spinlock = ATOMIC_FLAG_INIT; // 初始化自旋锁

void dowork(size_t thread_number, vector<size_t> &data)
{
    for (size_t i{0}; i < 10; ++i)
    {
        while (spinlock.test_and_set()) // 自旋锁尝试获得锁
        {
            data.push_back(thread_number);
            cout << thread_number << endl;
            spinlock.clear();
        }
    }
}

int main()
{
    // vector<size_t> data;
    // vector<thread> threads;
    // for (size_t i{0}; i < 10; ++i)
    // {
    //     threads.push_back(thread{dowork, i, ref(data)});
    // }
    // for (auto &t : threads)
    // {
    //     t.join();
    // }
    // cout << "finish\n";
    // return 0;
    cout << "start" << endl;
    mutex mtx1;
    mtx1.lock();
    mtx1.lock();
    mtx1.unlock();
    mtx1.unlock();
    cout << "finish";
    return 0;
}