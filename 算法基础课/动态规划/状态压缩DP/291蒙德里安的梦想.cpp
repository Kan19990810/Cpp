#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << N;

int n, m;

LL f[N][M];
vector<int> state[M];
bool st[M];

int main()
{
    while (cin >> n >> m, n || m)
    {
        // 1 << n 所有可能的状态 状态遍历
        // 预处理 记录合法状态- 可以拼成完整棋盘
        for (int i = 0; i < 1 << n; i++)
        {
            // cnt 连续为0 的个数
            int cnt = 0;
            bool is_valid = true;
            for (int j = 0; j < n; j++)
            {
                // i 的 第j个位置为1
                if (i >> j & 1)
                {
                    // 当前的0的个数为奇数则不合法
                    if (cnt & 1)
                    {
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                }
                // i 的 第j个位置为0
                else
                    cnt++;
            }
            if (cnt & 1)
                is_valid = false;
            st[i] = is_valid;
        }

        // 状态i 前面可以接哪些状态
        for (int i = 0; i < 1 << n; i++)
        {
            state[i].clear();
            for (int j = 0; j < 1 << n; j++)
            {
                if ((i & j) == 0 && st[i | j])
                    state[i].push_back(j);
            }
        }

        memset(f, 0, sizeof(f));
        // 第一列状态为 0 表示方案数1
        f[0][0] = 1;
        // 遍历每列
        for (int i = 1; i <= m; i++)
            // 遍历每列可能的状态
            for (int j = 0; j < 1 << n; j++)
                // 遍历每列可能的前状态
                for (auto k : state[j])
                    // 状态转移， 前状态f[i - 1][k] -> f[i][j]
                    f[i][j] += f[i - 1][k];

        // 最终状态为 超出一列 m 状态为 0
        cout << f[m][0] << endl;
    }

    return 0;
}
