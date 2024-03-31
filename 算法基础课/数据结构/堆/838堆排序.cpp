// 插入一个数、求最小值、删除最小值
// 堆 完全二叉树
// 左儿子 2x 右儿子 2x + 1
// down  up

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int h[N], s;

// 选取前m小的数
// 使用二叉树模拟，将大的数下沉
void down(int u)
{
    int t = u;
    if (u * 2 <= s && h[u * 2] < h[t])
        t = u * 2;
    if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t])
        t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
    }

    s = n;

    // 保证最大的一半数都在最底层
    // 从n/ 2 递减，则使得最小数在h[1]
    for (int i = n / 2; i; i--)
        down(i);

    for (int i = 0; i < m; i++)
    {
        printf("%d ", h[1]);
        swap(h[1], h[s]);
        s--;
        down(1);
    }
    return 0;
}