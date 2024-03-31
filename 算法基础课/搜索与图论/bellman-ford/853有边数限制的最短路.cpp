#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];

// 用数据结构Edge记录
struct Edge
{
    int a, b, w;
} edges[M];

// 有边树限制的最短路
int bellman()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    // 只更新k次
    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof(dist));
        // 遍历所有边,进行更新
        // Dijkstra 只遍历点
        for (int j = 0; j < m; j++)
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    return dist[n];
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges[i] = {x, y, z};
    }

    int t = bellman();

    if (t > 0x3f3f3f3f / 2)
        puts("impossible");
    else
        cout << t << endl;

    return 0;
}