#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int e[N], ne[N], h[N], idx;
int color[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

// 深度优先遍历
bool dfs(int x, int c)
{
    color[x] = c;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        // 将未染色的变为3 - c, 1 -> 2, 2 -> 1
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c))
                return false;
        }
        // 相邻节点有相同则不为二分图
        else if (color[j] == c)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        // 将未染色的变为1
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = false;
                // 出错时立刻返回,因为可能有多个连通块
                break;
            }
        }
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}