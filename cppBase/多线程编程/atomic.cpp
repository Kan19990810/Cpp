#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

void increment(atomic<int> &counter)
{
    for (int i{0}; i < 100; ++i)
    {
        ++counter;
        this_thread::sleep_for(1ms);
    }
}

int main()
{
    // {
    //     atomic<int> val{10};
    //     cout << val << endl;
    //     // 获取原子类型的当前值，将给定的递增值添加到这个原子值
    //     int fetched{val.fetch_add(4)};
    //     cout << fetched << endl;
    //     cout << val << endl;
    //     return 0;
    // }

    atomic<int> counter{0};
    vector<thread> threads;

    for (int i{0}; i < 10; ++i)
    {
        threads.push_back(thread(increment, ref(counter)));
    }

    for (auto &t : threads)
    {
        t.join();
    }

    cout << counter << endl;
    return 0;
}