#include <bits/stdc++.h>
#include <thread>
using namespace std;

int *ptr;

void func1()
{
    cout << "func1 pre ptr:" << ptr << endl;
    int b = 2;
    ptr = &b;
    cout << "func1 cur ptr:" << ptr << endl;
}

void func2()
{
    cout << "func2 pre ptr:" << *ptr << endl;
    *ptr = 3;
    cout << "func2 cur ptr:" << *ptr << endl;
}

int main()
{
    int a = 1;
    ptr = &a;
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
}
