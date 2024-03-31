#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n, m;
int g[N][N], d[N];
bool st[N];

// 最小生成树, 每次选取距离最近的节点
int prim()
{
    memset(d, 0x3f, sizeof(d));
    int res = 0;

    // 需要选取n个节点
    for (int i = 0; i < n; i++)
    {
        // t = -1 选取根节点
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || d[t] > d[j]))
            {
                t = j;
            }
        }

        if (i && d[t] == 0x3f3f3f3f)
            return 0x3f3f3f3f;

        if (i)
            res += d[t];

        // 更新节点距离, d[j] 为生成树与未选中节点的距离
        // Dijkstra 为起始节点与未选中节点的距离
        for (int j = 1; j <= n; j++)
        {
            d[j] = min(d[j], g[t][j]);
        }

        st[t] = true;
    }

    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof(g));

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int t = prim();

    if (t > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}
