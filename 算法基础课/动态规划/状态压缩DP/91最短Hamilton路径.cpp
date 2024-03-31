#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 22, M = 1 << 20;

int n;
// dp M 代表经过的点， N 代表结束的点
int f[M][N], weight[N][N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> weight[i][j];
        }
    }

    memset(f, 0x3f, sizeof(f));

    f[1][0] = 0;
    // 遍历每一种状态， 初始->最终
    for (int i = 0; i < 1 << n; i++)
        // 遍历走过的点 作为终点
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                // 遍历中间点
                for (int k = 0; k < n; k++)
                    if (i - (1 << j) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j]);

    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}