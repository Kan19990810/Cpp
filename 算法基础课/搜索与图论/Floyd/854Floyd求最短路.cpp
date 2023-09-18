// k个询问

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 1e9;

int n, m , k;
int d[N][N];

void floyd()
{
    for(int t =1 ;t <= n; t ++)
    {
        for(int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][t] + d[t][j]);
            }
        }
    }
}


int main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n ; j++)
        {
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }


    while( m--)
    {
        int x, y ,z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }

    floyd();

    while (k --)
    {
        int x, y;
        cin >> x >> y;

        if(d[x][y] > INF / 2) puts("impossible");
        else cout << d[x][y] << endl;
    }

    return 0;
}