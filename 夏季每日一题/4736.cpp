#include <iostream>

using namespace std;

const int N = 1010, M = 35;

int d[N][M];
int n, m, p, T;

int main()
{
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d", &n, &m, &p);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                scanf("%d", &d[i][j]);
            }
        }

        long long res = 0;
        for(int i = 1; i <= m; i++)
        {
            int flog = 0, maxv = 0;
            for(int j = 1; j <= n; j++)
            {
                maxv = max(maxv, d[j][i]);
                if(j == p) flog = d[j][i];
            }
            res += maxv - flog;
        }

        printf("Case #%d: %d\n", t, res);
    }

    return 0;
}