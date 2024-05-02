#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(Edge &W)
    {
        return w < W.w;
    }
};

class Union
{
private:
    vector<int> parent;

public:
    Union(int n) : parent(n)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    };
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unit(int x, int y)
    {
        int paX = find(x);
        int paY = find(y);
        if (paX != paY)
        {
            parent[paX] = paY;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end());

    Union uni(n + 1);
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int paU = uni.find(u);
        int paV = uni.find(v);
        if (paU != paV)
        {
            ans += w;
            cnt++;
            uni.unit(paU, paV);
        }
    }

    if (cnt != n - 1)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}