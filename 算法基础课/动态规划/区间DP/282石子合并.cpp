#include <iostream>
#include <algorithm>

using namespace std;

const int N = 310;

int s[N];
int dp[N][N];

int main()
{
    int n;
    cin >> n;

    // 前缀和求区间和
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    // dp[i][j] 合并i - j为一堆的最低代价
    // len = 2 最少为 2 堆石子开始
    // 枚举区间长度
    for (int len = 2; len <= n; len++)
    {
        // 枚举区间开端
        for (int i = 1; i + len - 1 <= n; i++)
        {
            // j 大于 i
            // dp[i][i]默认为0
            int j = i + len - 1;
            dp[i][j] = 1e8;
            for (int k = i; k < j; k++)
                //  状态转移， 由区间短的->区间长的
                // 需要保证区间短的状态为最优状态
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}