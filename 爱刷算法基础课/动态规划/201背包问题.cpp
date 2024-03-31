#include <iostream>
using namespace std;

const int N = 1010;
int dp[N], v[N], w[N];
int n, m, res;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    // for (int j = 0; j <= m; j++)
    // {
    //     res = max(res, dp[n][j]);
    // }

    cout << dp[m] << endl;
    return 0;
}