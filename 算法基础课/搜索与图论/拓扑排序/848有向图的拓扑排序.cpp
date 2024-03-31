#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;

int h[N], e[N], ne[N], idx;

// d 入度
// q 记录的入列的顺序
int q[N], d[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

bool topsort()
{
    int hh = 0, tt = -1;
    // 拓扑序列的起点 入度为0的点
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q[++tt] = i;
        }
    }

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;

            // 一旦入度为0，则入列
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
    cin >> n >> m;

    memset(h, -1, sizeof(h));

    while (m--)
    {
        int x, y;
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
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}