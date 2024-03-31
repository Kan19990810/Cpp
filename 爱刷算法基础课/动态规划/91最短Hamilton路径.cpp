#include <iostream>
#include <cstring>

using namespace std;

const int N = 21, M = 1 << 20;
// dp M 代表经过的点， N 代表结束的点
long long dp[M][N];
int a[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            // 剪枝， i 中应该包含 j
            if (i >> j & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    // 剪枝， 保证终点为 j
                    if (i - (1 << j) >> k & 1)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j]);
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}