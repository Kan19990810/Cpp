#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int dp[N][N];
char a[N], b[N];

// 最长公共子序列
int main()
{
    int n, m;
    cin >> n >> m >> a + 1 >> b + 1;
    // dp[i][j] 以a[i]和b[j]结尾字符串的最长公共子序列
    // 状态转移由 dp[i - 1][j]、dp[i][j - 1]、dp[i - 1][j - 1]而来
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    cout << dp[n][m];

    return 0;
}