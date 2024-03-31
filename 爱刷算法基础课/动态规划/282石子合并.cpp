#include <iostream>
using namespace std;

const int N = 310, INF = 1e9;
int dp[N][N], a[N], s[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dp[i][j] = INF;
        }
    }

    for (int i = n; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}