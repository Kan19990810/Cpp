#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N], q[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // q储存当前的递增子序列
    q[0] = -2e9;
    int len = 0;
    // 并非动态规划思路
    for (int i = 0; i < n; i++)
    {
        // 二分查找a[i]在q中的位置
        int l = 0, r = len;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        // r + 1 为以a[i]结尾的最长递增子序列
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    cout << len << endl;

    return 0;
}