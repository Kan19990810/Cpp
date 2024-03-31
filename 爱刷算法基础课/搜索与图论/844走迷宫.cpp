// 用队列模拟 BFS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n, m;
int map[N][N], dist[N][N];
pair<int, int> q[N * N];
int tt, hh;

int bfs()
{
    memset(dist, -1, sizeof(dist));
    q[0] = {1, 1};
    dist[1][1] = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

    while (hh <= tt)
    {
        pair<int, int> k = q[hh];
        hh++;
        int d = dist[k.first][k.second];
        for (int i = 0; i < 4; i++)
        {
            int x = k.first + dx[i], y = k.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && map[x][y] == 0 && dist[x][y] == -1)
            {
                tt++;
                q[tt] = {x, y};
                dist[x][y] = d + 1;
            }
        }
    }
    return dist[n][m];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << bfs();
    return 0;
}