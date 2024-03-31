#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2010;

int dp[N];

struct Good
{
    int v;
    int w;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Good> goods;

    for (int i = 1; i <= n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        // 将件数使用二进制表示 拆分成不同物件
        for (int k = 1; k <= s; k *= 2)
        {
            s -= k;
            goods.push_back({v * k, w * k});
        }

        if (s > 0)
            goods.push_back({v * s, w * s});
    }
    // 01背包问题
    for (Good good : goods)
    {
        for (int j = m; j >= good.v; j--)
            dp[j] = max(dp[j], dp[j - good.v] + good.w);
    }

    cout << dp[m] << endl;

    return 0;
}