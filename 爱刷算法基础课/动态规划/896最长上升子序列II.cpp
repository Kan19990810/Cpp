#include <iostream>
using namespace std;

const int N = 100010;
int a[N], q[N];
int s = 0, n, l, r, mid;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    q[0] = -2e9;
    for (int i = 1; i <= n; i++)
    {
        l = 0, r = s;
        while (l < r)
        {
            mid = (l + r + 1) >> 1;
            // 当所有数都小于a[i]， 则数组长度 + 1
            if (q[mid] < a[i])
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        q[l + 1] = a[i];
        s = max(s, l + 1);
    }

    cout << s;
    return 0;
}