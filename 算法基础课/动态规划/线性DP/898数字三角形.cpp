#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 1e9;

int a[N][N], dp[N][N];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            dp[i][j] = -INF;

    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            // dp[i][j]由dp[i - 1][j - 1]和dp[i - 1][j]转移而来
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];

    int ans = -INF;

    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}