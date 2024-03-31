#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m, x, y, z;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        st[t] = true;
        for (int k = 1; k <= n; k++)
        {
            dist[k] = min(dist[k], dist[t] + g[t][k]);
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
    memset(dist, 0x3f, sizeof(dist));
    while (m--)
    {
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    cout << dijkstra() << endl;
    return 0;
}