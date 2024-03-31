#include <iostream>
#include <string>

using namespace std;

const int N = 1010;
int dp[N][N];
string a, b;
int n, m;

int main()
{
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[n][m];
    return 0;
}