#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int x, int y, int z)
{
    w[idx] = z, e[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

int spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while(q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];

}


int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof(h));

    while(m -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        
    }

    int t = spfa();

    if (t == 0x3f3f3f3f) puts("impossible");
    else cout << t << endl;

    return 0;
}