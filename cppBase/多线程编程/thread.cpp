#include <thread>
#include <iostream>

using namespace std;

void counter(int i, int j)
{
    cout << i << ' ' << j << endl;
}

class Counter
{
private:
    int i, j;

public:
    Counter(int x, int y) : i(x), j(y) {}
    void operator()() const
    {
        cout << i << ' ' << j << endl;
    }
};

class request
{
private:
    int i, j;

public:
    request(int x, int y) : i(x), j(y) {}
    void print()
    {
        cout << i << ' ' << j << endl;
    }
};

int n = 0;
thread_local int k = 0;

void print()
{
    cout << n << ' ' << k << endl;
    n++;
    k++;
}

int main()
{
    // {
    //     thread t1(counter, 1, 2);
    //     thread t2(counter, 3, 4);
    //     t1.join();
    //     t2.join();
    // }

    // {
    //     thread t1(Counter(1, 2));
    //     Counter counter(3, 4);
    //     thread t2(counter);
    //     t1.join();
    //     t2.join();
    // }

    // {
    //     thread t1([]()
    //               { cout << 1 << ' ' << 2 << endl; });
    //     thread t2([]()
    //               { cout << 3 << ' ' << 4 << endl; });
    //     t1.join();
    //     t2.join();
    // }

    // {
    //     request req{1, 2};
    //     thread t(&request::print, &req);
    //     t.join();
    // }

    {
        thread t1(print);

        thread t2(print);
        t2.join();
        t1.join();
    }
    return 0;
}