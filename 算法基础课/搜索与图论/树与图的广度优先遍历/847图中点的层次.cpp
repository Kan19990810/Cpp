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
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int bfs()
{
    int tt = 0, hh = 0;
    memset(d, -1, sizeof(d));
    q[0] = 1;
    d[1] = 0;

    while(hh <= tt)
    {
        int t = q[hh ++];
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
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

    while ( m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}