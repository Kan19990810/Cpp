#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;

int happy[N];
int h[N], e[N], ne[N], idx;
int f[N][2];
bool has_father[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    // f[u][1] 参加 f[u][0] 不参加
    f[u][1] = happy[u];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        // dfs(j) 处理完 f[j][1] f[j][0]
        // 处理完子任务，再来处理父任务
        // 回溯
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }

    memset(h, -1, sizeof(h));

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;
        add(b, a);
    }

    // 找到根节点
    int root = 1;
    while (has_father[root])
        root++;

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}