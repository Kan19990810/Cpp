#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int dp[N];
int v[N], w[N];

// 每件物品只能使用一次。
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // 遍历物品
    for (int i = 1; i <= n; i++)
        // 遍历体积, m -> v[i] 每件物品只能使用一次
        for (int j = m; j >= v[i]; j--)
            // 选或不选, 选择价值最大值
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}