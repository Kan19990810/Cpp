#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 12, M = 1 << N;
vector<int> state[M];
long long dp[N][M];
bool st[M];

int main()
{
    int n, m;
    while (cin >> n >> m, (n || m))
    {
        // 第 i 种情况是否单独合理， 可以通过 2 * 1 方块将自己填满
        for (int i = 0; i < (1 << n); i++)
        {
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j++)
            {
                if (i >> j & 1)
                {
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                else
                {
                    cnt++;
                }
            }
            if (cnt & 1)
            {
                is_valid = false;
            }
            st[i] = is_valid;
        }

        // 合理的前状态
        for (int i = 0; i < (1 << n); i++)
        {
            state[i].clear();
            for (int j = 0; j < (1 << n); j++)
            {
                if ((i & j) == 0 && st[i | j])
                {
                    state[i].push_back(j);
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < 1 << n; j++)
            {
                for (auto k : state[j])
                {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}
