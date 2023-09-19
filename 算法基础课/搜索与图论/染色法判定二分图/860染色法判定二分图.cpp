#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 200010;

int n, m;
int e[N], ne[N], h[N], idx;
int color[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx ++; 
}

bool dfs(int x, int c)
{
    color[x] = c;
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if(!dfs(j, 3 - c)) return false;
        }
        else if(color[j] == c) return false;
    }
    return true;
}


int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h)) ;
    while(m --)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if(!dfs(i, 1))
            {
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");

    return 0;

}