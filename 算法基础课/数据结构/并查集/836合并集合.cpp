// 1 将两个集合并
// 2 询问两个元素是否在一个集合中

// 基本原理：用树模拟集合

// 判断是否为根节点 p[x] == x
// 查找集合编号 while(p[x] != x) x = p[x]
// 合并集合 p[x] = y
// 路径压缩

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
    // 路径压缩
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 1; i <= m; i++)
    {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        // find()找到祖先
        if (op[0] == 'M')
            p[find(a)] = find(b);
        else
        {
            // 如果是同一祖先则为同一集合
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}