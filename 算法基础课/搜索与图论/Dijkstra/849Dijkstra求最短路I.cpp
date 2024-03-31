#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

// 求一点到一点的最短距离,边权为正值
int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    // O(N^2)
    // 需要更新n次,将所有点纳入
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        // 找到没有遍历过且距离最近的点
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        st[t] = true;

        // 由最近的点更新到其他点的距离
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }

    if (dist[n] == 0x3f3f3f3f)
    {
        return -1;
    }

    return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));

    // 紧密图使用g[x][y]记录
    // 疏松图用链表记录
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}