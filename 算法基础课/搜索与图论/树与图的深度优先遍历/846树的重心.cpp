#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;
bool s[N];

int ans = N;

// b 为 a 的儿子
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 返回值 以u为根节点的点数
int dfs(int u)
{
    s[u] = true;

    int sum = 1, res = 0;
    // 遍历u的儿子
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 树结构，不回到父结点
        if (!s[j])
        {
            // 处理完子任务，再处理父任务
            int r = dfs(j);
            // 比较各个儿子节点的点数
            res = max(res, r);
            // sum 以自己为根节点的点数
            sum += r;
        }
    }
    // n - sum 父结点的点数
    res = max(res, n - sum);

    ans = min(res, ans);
    return sum;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n;

    // 构建树/图
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}