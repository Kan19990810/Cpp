#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n;
int dp[N];

int main()
{
    cin >> n;
    // 什么也不需要额外添加也是一种方案
    dp[0] = 1;
    // i 表示要添加的数
    for (int i = 1; i <= n; i++)
        // 正向遍历，完全背包可以无限次添加
        for (int j = i; j <= n; j++)
            // 将当前的正整数 i 添加到拆分结果中所得到的拆分方式数量
            // j == i 时表示添加完i 后则没有其他数了，故dp[0] = 0
            dp[j] = (dp[j] + dp[j - i]) % mod;

    cout << dp[n] << endl;

    return 0;
}