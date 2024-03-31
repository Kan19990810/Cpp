#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

// m 表示第几个插入的数
// s 表示当前堆h的大小
// qh[N] 第几个插入的数在h中的位置的映射
int n;
int h[N], s, m;
int qh[N], hq[N];

// 交换堆h中的位置
void heap_swap(int a, int b)
{
    swap(qh[hq[a]], qh[hq[b]]);
    swap(hq[a], hq[b]);
    swap(h[a], h[b]);
}

void down(int a)
{
    int t = a;
    if (a * 2 <= s && h[a * 2] < h[t])
        t = a * 2;
    if (a * 2 + 1 <= s && h[a * 2 + 1] < h[t])
        t = a * 2 + 1;
    if (t != a)
    {
        heap_swap(t, a);
        down(t);
    }
}

void up(int a)
{
    while (a / 2 && h[a] < h[a / 2])
    {
        heap_swap(a, a / 2);
        a /= 2;
    }
}

int main()
{
    scanf("%d", &n);
    // m 表示第几个插入的数
    m = 0;
    // s 表示当前堆h的大小
    s = 0;
    for (int i = 1; i <= n; i++)
    {
        char op[3];
        int k, x;
        scanf("%s", op);
        if (op[0] == 'I')
        {
            scanf("%d", &x);
            m++;
            s++;
            h[s] = x;
            qh[m] = s, hq[s] = m;
            up(s);
        }

        else if (op[0] == 'P' && op[1] == 'M')
        {
            printf("%d\n", h[1]);
        }

        else if (op[0] == 'D' && op[1] == 'M')
        {
            heap_swap(1, s--);
            down(1);
        }

        else if (op[0] == 'D')
        {
            scanf("%d", &k);
            int t = qh[k];
            heap_swap(t, s--);
            down(t);
            up(t);
        }

        else if (op[0] == 'C')
        {
            scanf("%d%d", &k, &x);
            // 找到第k个数在h中的位置，进行操作
            int t = qh[k];
            h[t] = x;
            down(t);
            up(t);
        }
        // cout << m << ' '<<' '<< s <<' '<< h[1] << endl;
    }
    return 0;
}