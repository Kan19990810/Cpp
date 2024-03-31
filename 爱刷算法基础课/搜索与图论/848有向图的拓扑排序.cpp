// 入度概念
#include <iostream>
#include <cstring>

using namespace std;
const int N = 100010;
int e[N], ne[N], h[N], idx;
int d[N], q[N], tt, hh;
int n, m, x, y;

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool topsort()
{
    tt = -1, hh = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q[++tt] = i;
        }
    }
    while (hh <= tt)
    {
        int k = q[hh++];
        for (int i = h[k]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (d[j] == 0)
            {
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }

    if (topsort())
    {
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << ' ';
        }
    }
    else
    {
        cout << -1;
    }
    return 0;
}