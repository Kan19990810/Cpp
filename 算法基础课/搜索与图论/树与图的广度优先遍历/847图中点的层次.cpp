#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n, m;

int h[N], e[M], ne[M], idx;

int d[N], q[N];

void add(int a, int b)
{
    // 头插法 链表里记录idx, 再由e[idx]获取编号
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    int tt = 0, hh = 0;
    memset(d, -1, sizeof(d));
    q[0] = 1;
    d[1] = 0;

    while (hh <= tt)
    {
        int t = q[hh++];
        // 遍历t的儿子
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            // 如果没有遍历过，继续操作
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q[++tt] = j;
            }
        }
    }

    return d[n];
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}