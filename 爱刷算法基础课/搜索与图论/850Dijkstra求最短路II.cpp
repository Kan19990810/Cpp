#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 1500010;
int e[N], ne[N], h[N], w[N], idx;
int dist[N];
bool st[N];
priority_queue<PII, vector<PII>, greater<PII>> heap;
int n, m, x, y, z;

void add(int x, int y, int z)
{
    e[idx] = y;
    ne[idx] = h[x];
    w[idx] = z;
    h[x] = idx++;
}

int dijkstra()
{
    dist[1] = 0;
    heap.push({0, 1});
    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int d = t.first, id = t.second;
        if (st[id])
        {
            continue;
        }
        st[id] = true;
        for (int i = h[id]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > d + w[i])
            {
                dist[j] = d + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
    {
        return -1;
    }
    return dist[n];
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(h, -1, sizeof(h));
    cin >> n >> m;

    while (m--)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra();
    return 0;
}