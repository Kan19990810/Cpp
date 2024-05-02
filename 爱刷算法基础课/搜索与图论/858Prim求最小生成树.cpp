#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int prim(vector<vector<int>> g)
{
    int n = g.size() - 1;
    vector<bool> st(n + 1, false);
    vector<int> d(n + 1, INT_MAX / 2);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int t = -1;
        for (int j = 1; j <= n; ++j)
        {
            if (!st[j] && (t == -1 || d[t] > d[j]))
            {
                t = j;
            }
        }
        if (i != 1 && d[t] > INT_MAX / 3)
        {
            return INT_MAX / 3;
        }

        if (i != 1)
        {
            ans += d[t];
        }
        st[t] = true;

        for (int j = 1; j <= n; ++j)
        {
            d[j] = min(d[j], g[t][j]);
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX / 2));
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    int t = prim(g);
    if (t > INT_MAX / 4)
        cout << "impossible" << endl;
    else
        cout << t << endl;
    return 0;
}