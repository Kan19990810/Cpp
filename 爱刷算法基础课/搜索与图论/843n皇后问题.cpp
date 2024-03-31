#include <iostream>
using namespace std;

const int N = 10;
int n;
char q[N][N];
bool col[N], row[N], d[2 * N], nd[2 * N];

void dfs(int x, int y, int s)
{
    if (x == n)
    {
        y++;
        x = 0;
    }

    if (y == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << q[i][j];
                }
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    dfs(x + 1, y, s);

    if (!col[x] && !row[y] && !d[n - 1 + y - x] && !nd[x + y])
    {
        q[x][y] = 'Q';
        col[x] = true;
        row[y] = true;
        d[n - 1 + y - x] = true;
        nd[x + y] = true;
        dfs(x + 1, y, s + 1);
        q[x][y] = '.';
        col[x] = false;
        row[y] = false;
        d[n - 1 + y - x] = false;
        nd[x + y] = false;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i][j] = '.';
        }
    }
    dfs(0, 0, 0);
    return 0;
}