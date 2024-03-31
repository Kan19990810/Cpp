#include <iostream>
using namespace std;

int n, x;
int lowbit(int x)
{
    return x & (-x);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        int res = 0;
        while (x)
        {
            x -= lowbit(x);
            res++;
        }
        cout << res << ' ';
    }
    return 0;
}