#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int dp[N];

// 每个物品 有限件
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        // 与01背包一致 m -> 0
        for (int j = m; j >= 0; j--)
            // 选择件数
            for (int k = 0; k <= s && k * v <= j; k++)
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
    }

    cout << dp[m] << endl;

    return 0;
}