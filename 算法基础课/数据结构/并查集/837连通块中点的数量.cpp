#include <iostream>
using namespace std;

const int N = 100010;

int n, m;

// s[N]只有祖先记录的数据有效， 连通块中点的数量
int p[N], s[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        s[i] = 1;
    }

    for (int i = 1; i <= m; i++)
    {
        char op[3];
        int a, b;

        scanf("%s", op);
        if (op[0] == 'C')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                continue;

            s[find(b)] += s[find(a)];
            p[find(a)] = find(b);
        }

        else if (op[1] == '1')
        {
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", s[find(a)]);
        }
    }
    return 0;
}