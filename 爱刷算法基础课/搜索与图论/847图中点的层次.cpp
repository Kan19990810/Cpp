#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010, M = 2 * N;
int e[M], ne[M], h[N], d[N], idx;
queue<int> q;
int n, m, a, b;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int bfs()
{
    q.push(1);
    d[1] = 0;

    while (q.size())
    {
        int k = q.front();
        q.pop();
        for (int j = h[k]; j != -1; j = ne[j])
        {
            int t = e[j];
            if (d[t] == -1)
            {
                d[t] = d[k] + 1;
                q.push(t);
            }
        }
    }
    return d[n];
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;
    return 0;
}