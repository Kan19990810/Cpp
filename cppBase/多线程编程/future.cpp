#include <future>
#include <thread>
#include <iostream>
using namespace std;

void dowork(promise<int> thepromise)
{
    thepromise.set_value(42);
}

int calculate()
{
    return 12;
}

int main()
{
    // {
    //     promise<int> mypromise;
    //     auto future{mypromise.get_future()};
    //     thread thethread{dowork, move(mypromise)};

    //     int result{future.get()};
    //     cout << result << endl;
    //     thethread.join();
    // }

    // {
    //     packaged_task<int(int, int)> task{calculate};
    //     auto thefuture{task.get_future()};
    //     thread thethread{move(task), 10, 20};
    //     int result{thefuture.get()};
    //     cout << result << endl;
    //     thethread.join();
    // }

    {
        auto myfuture{async(calculate)};
        int result{myfuture.get()};
        cout << result << endl;
    }

    return 0;
}