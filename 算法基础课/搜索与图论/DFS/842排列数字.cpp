// dfs 爆搜
// 枚举
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u)
{
    // 设置终止条件
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }
    // 枚举选哪一个
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            // st[i] = false; 后接i++ 因此需要恢复环境
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}