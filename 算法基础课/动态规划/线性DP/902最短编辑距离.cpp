#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

char a[N], b[N];
int dp[N][N];

int main()
{
    int n, m;
    scanf("%d%s%d%s", &n, a + 1, &m, b + 1);
    // dp[i][j] a[i] 和 b[j] 的最短编辑距离
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            // 状态转移 dp[i - 1][j] 、dp[i][j - 1]、dp[i - 1][j - 1]
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    cout << dp[n][m];

    return 0;
}