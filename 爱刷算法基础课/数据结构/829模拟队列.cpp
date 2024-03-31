#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int head, tail;
int l[N];

void init()
{
    head = 0;
    tail = 0;
}

int main()
{
    init();
    int m;
    cin >> m;
    while (m--)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int x;
            cin >> x;
            l[tail++] = x;
        }
        else if (str == "pop")
        {
            head++;
        }
        else if (str == "empty")
        {
            if (head >= tail)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << l[head] << endl;
        }
    }
    return 0;
}