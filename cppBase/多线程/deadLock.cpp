#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void func1()
{
    cout << " ******* start func1 ******" << endl;
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lock2(mtx2);
}

void func2()
{
    cout << " ******* start    func2   ******" << endl;
    lock_guard<mutex> lock1(mtx2);
    this_thread::sleep_for(chrono::seconds(1));
    lock_guard<mutex> lock2(mtx1);
}

int main()
{
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
    return 0;
}
