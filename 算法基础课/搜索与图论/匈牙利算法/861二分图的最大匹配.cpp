#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

// 两两 匹配
// 递归方法
bool find(int x)
{
    // 遍历与节点相关联的点
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        // 在该轮中没有尝试
        // 防止find(match[j])陷入死循环 j没办法匹配 x 则也无法匹配match[j]
        if (!st[j])
        {
            st[j] = true;
            // 该点没有被选择或者原先选择的可以改变对象
            if (match[j] == 0 || find(match[j]))
            {
                // x 匹配了 y
                match[j] = x;
                // 匹配成功
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // 由左半部分找右半部分
        add(u, v);
    }

    int res = 0;
    // 遍历左半部分,尝试为左半所有点找到匹配
    for (int i = 1; i <= n1; i++)
    {
        // st 表示对于右半部分的尝试
        memset(st, false, sizeof(st));
        // 成功找到则结果++
        if (find(i))
            res++;
    }

    cout << res << endl;

    return 0;
}