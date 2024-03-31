#include <iostream>
#include <cstring>
using namespace std;

// 递归
const int N = 310;
int s[N][N], dp[N][N];
int r, c;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int res;

void dfs(int x, int y)
{

    if (dp[x][y] != -1)
    {
        return;
    }

    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 1 && a <= r && b >= 1 && b <= c && s[x][y] > s[a][b])
        {
            dfs(a, b);
            dp[x][y] = max(dp[x][y], dp[a][b] + 1);
        }
    }
    return;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            dfs(i, j);
            res = max(res, dp[i][j]);
        }
    }

    cout << res << endl;
    return 0;
}