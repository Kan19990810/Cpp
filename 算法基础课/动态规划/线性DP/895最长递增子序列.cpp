#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int a[N], dp[N];

// 最长递增子序列， dp[i]为以a[i]结尾的最长递增子序列
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // dp[i]由所有比i小的j dp[j]转移而来
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}