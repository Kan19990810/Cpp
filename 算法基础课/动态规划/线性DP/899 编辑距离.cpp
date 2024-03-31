#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int N = 15, M = 1010;
char f[M][N];
int dp[N][N];

// 返回编辑距离
int edit_distance(char a[], char b[])
{
    int la = strlen(a + 1), lb = strlen(b + 1);

    for (int i = 0; i <= la; i++)
        dp[i][0] = i;
    for (int i = 0; i <= lb; i++)
        dp[0][i] = i;

    for (int i = 1; i <= la; i++)
        for (int j = 1; j <= lb; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            if (a[i] == b[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }

    return dp[la][lb];
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%s", f[i] + 1);

    while (m--)
    {
        char s[N];
        int k;

        scanf("%s%d", s + 1, &k);

        int res = 0;
        // 依次查询
        for (int i = 0; i < n; i++)
            if (edit_distance(f[i], s) <= k)
                res++;

        cout << res << endl;
    }

    return 0;
}