#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int dp[N], v[N], w[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j ++)
        {
            cin >> v[j] >> w[j];
        }

        for (int j = m; j >= 0; j --)
            for (int k = 1; k <= s; k++)
                if (j >= v[k]) dp[j] = max(dp[j], dp[j - v[k]] + w[k]);
    }

    cout << dp[m] << endl;

    return 0;
}