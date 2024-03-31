#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
int s[N], tt;

int main()
{
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
            s[++tt] = x;
        }
        else if (str == "pop")
        {
            tt--;
        }
        else if (str == "empty")
        {
            if (tt == 0)
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
            cout << s[tt] << endl;
        }
    }
    return 0;
}