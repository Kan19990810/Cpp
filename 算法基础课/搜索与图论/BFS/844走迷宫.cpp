#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

typedef pair<int, int> PII;

int n, m;
int g[N][N];
int d[N][N];
PII q[N * N];

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = {0, 0};

    memset(d, -1, sizeof(d));
    d[0][0] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            // d[x][y] == -1 判断条件保证d[x][y]记录最少移动次数
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> g[i][j];
    }

    cout << bfs();

    return 0;
}