#include <iostream>
using namespace std;

const int N = 100010;
int s[N];
int tt;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        while (tt > 0 && s[tt - 1] >= x)
        {
            tt--;
        }
        if (tt == 0)
        {
            cout << -1 << ' ';
        }
        else
        {
            cout << s[tt - 1] << ' ';
        }
        s[tt++] = x;
    }
    return 0;
}