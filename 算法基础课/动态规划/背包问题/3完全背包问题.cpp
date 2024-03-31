#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int dp[N];
int v[N], w[N];

// 每种物品都有无限件可用
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        // 选择体积 v[i] -> m 每种物品都有无限件可用
        for (int j = v[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}