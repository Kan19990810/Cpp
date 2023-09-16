#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1500010;

int n, m;
int e[N], ne[N], w[N], h[N], idx;
int dist[N];

bool st[N];

typedef pair<int, int> PII;

priority_queue<PII, vector<PII>, greater<PII>> heap;

void add(int x, int y, int z)
{
    e[idx] = y, ne[idx] = h[x], w[idx] = z, h[x] = idx ++; 
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));

    dist[1] = 0;

    heap.push({0, 1});

    while(heap.size())
    {
        PII t = heap.top();
        heap.pop();

        int ver= t.second, distance = t.first;

        if (st[ver]) continue;

        st[ver] = true;

        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if(dist[n] == 0x3f3f3f3f) return -1;

    return dist[n];
}


int main()
{
    cin >> n >> m;

    memset(h , -1 , sizeof(h));

    while (m --)
    {
        int x, y ,z;
        cin >> x >> y >> z;
        add(x, y, z);
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}