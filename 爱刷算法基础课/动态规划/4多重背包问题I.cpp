#include <iostream>
using namespace std;

const int N = 110;
int dp[N], v[N], w[N], s[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            for (int k = 1; k <= s[i] && k * v[i] <= j; k++)
            {
                dp[j] = max(dp[j], dp[j - v[i] * k] + k * w[i]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}