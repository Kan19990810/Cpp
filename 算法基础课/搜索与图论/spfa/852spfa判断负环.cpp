
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int x, int y, int z)
{
    w[idx] = z, e[idx] = y, ne[idx] = h[x], h[x] = idx ++;
}

bool spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    
    queue<int> q;
    for(int i = 1; i <= n ; i++)
    {
        q.push(i);
        st[i] = true;
    }

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
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n) return true;
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
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

    bool t = spfa();

    if (t) puts("Yes");
    else puts("No");

    return 0;
}