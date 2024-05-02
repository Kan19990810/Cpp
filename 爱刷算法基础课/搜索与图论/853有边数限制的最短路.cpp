#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct edge
{
public:
    int x;
    int y;
    int w;
};

int bell(vector<edge> &edges, vector<int> &dis, int k)
{
    int m = edges.size();
    int n = dis.size() - 1;
    dis[1] = 0;
    while (k--)
    {
        vector<int> tmp{dis};
        for (int i = 0; i < m; ++i)
        {
            auto edge = edges[i];
            int x = edge.x;
            int y = edge.y;
            int w = edge.w;
            dis[y] = min(dis[y], tmp[x] + w);
            // cout << "y: " << y << " dis[y]:" << dis[y] << endl;
        }
    }
    return dis[n];
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> edges;
    vector<int> dis(n + 1, INT_MAX / 2);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }
    int t = bell(edges, dis, k);
    if (t >= INT_MAX / 5)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}
