#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floyd(vector<vector<int>> &g)
{
    int n = g.size() - 1;
    for (int mid = 1; mid <= n; ++mid)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                g[i][j] = min(g[i][j], g[i][mid] + g[mid][j]);
            }
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX / 2));

    for (int i = 1; i <= n; ++i)
    {
        g[i][i] = 0;
    }

    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }

    floyd(g);

    while (k--)
    {
        int x, y;
        cin >> x >> y;
        if (g[x][y] > INT_MAX / 4)
            cout << "impossible" << endl;
        else
            cout << g[x][y] << endl;
    }
    return 0;
}