#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge
{
    int a, b, w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
} edge[N];

int find(int a)
{
    if (a != p[a])
        p[a] = find(p[a]);
    return p[a];
}

// 并查集
// 从最小边遍历到最大边
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = {u, v, w};
    }

    sort(edge, edge + m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    int res = 0, cnt = 0;

    for (int i = 0; i < m; i++)
    {
        int a = edge[i].a, b = edge[i].b, w = edge[i].w;

        a = find(a), b = find(b);

        if (a != b)
        {
            res += w;
            cnt += 1;
            p[a] = b;
        }
    }

    if (cnt < n - 1)
        puts("impossible");
    else
        cout << res << endl;

    return 0;
}