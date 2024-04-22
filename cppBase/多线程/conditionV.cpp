#include <condition_variable>
#include <thread>
#include <iostream>
#include <deque>

using namespace std;

class BlockQueue
{
private:
    deque<int> blockqueue;

    int capacity;
    mutex mtx;
    condition_variable condConsumer;
    condition_variable condProducter;

public:
    BlockQueue(int cap) : capacity(cap){};

    void push(int x)
    {
        unique_lock<mutex> lock(mtx);
        while (blockqueue.size() >= capacity)
        {
            condProducter.wait(lock);
        }
        blockqueue.push_back(x);
        condConsumer.notify_one();
    };

    int pop()
    {
        unique_lock<mutex> lock(mtx);
        while (blockqueue.size() == 0)
        {
            condConsumer.wait(lock);
        }
        int x = blockqueue.front();
        blockqueue.pop_front();
        condProducter.notify_one();
        return x;
    }
};

BlockQueue bq(3);

void productFun()
{
    for (int i = 0; i < 30; ++i)
    {
        bq.push(1);
        cout << "push one" << endl;
    }
}

void consumerFun()
{
    this_thread::sleep_for(chrono::seconds(1));

    for (int i = 0; i < 30; ++i)
    {
        int x = bq.pop();
        cout << "comsum : " << x << endl;
    }
}

int main()
{
    thread t1(productFun);
    thread t2(consumerFun);
    t1.join();
    t2.join();
    return 0;
}