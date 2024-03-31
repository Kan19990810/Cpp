#include <iostream>
using namespace std;

const int N = 100010;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    int n, k, res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        d[i] = 0;
    }
    while (k--)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if (x > n || y > n)
        {
            res++;
        }
        else
        {
            int p_x = find(x);
            int p_y = find(y);
            if (c == 1)
            {
                if (p_x == p_y && (d[x] - d[y]) % 3 != 0)
                {
                    res++;
                }
                else if (p_x != p_y)
                {
                    p[p_x] = p_y;
                    d[p_x] = d[y] - d[x];
                }
            }
            else
            {
                if (p_x == p_y && (d[x] - d[y] - 1) % 3 != 0)
                {
                    res++;
                }
                else if (p_x != p_y)
                {
                    p[p_x] = p_y;
                    d[p_x] = d[y] - d[x] + 1;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}