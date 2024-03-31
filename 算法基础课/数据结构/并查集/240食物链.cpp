#include <iostream>

using namespace std;

const int N = 50010;

int p[N], d[N];
int n, k;

int find(int x)
{
    if (p[x] != x)
    {
        // t x的祖先， p[x] x的旧父亲
        // find(p[x]) x的旧父亲数据更新了，x的数据未更新
        // d[p[x]] x的旧父亲与祖先的距离
        // d[x] += d[p[x]]; d[x] 从与父亲的距离更新到与祖先的距离
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }

    int res = 0;

    for (int i = 1; i <= k; i++)
    {
        int t, x, y;

        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n)
        {
            res++;
        }
        else
        {
            int px = find(x);
            int py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                else if (px != py)
                {
                    p[px] = p[y];
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d", res);
    return 0;
}