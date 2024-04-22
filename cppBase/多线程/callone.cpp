#include <thread>
#include <mutex>
#include <vector>
#include <iostream>

using namespace std;

once_flag onceFlag;

void init()
{
    cout << "init\n";
}

void process()
{
    call_once(onceFlag, init);
    cout << "process\n";
}

int main()
{
    vector<thread> threads{3};
    for (auto &t : threads)
    {
        t = thread{process};
    }
    for (auto &t : threads)
    {
        t.join();
    }
    return 0;
}