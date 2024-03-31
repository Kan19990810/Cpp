#include <iostream>
#include <string>
using namespace std;

const int N = 1010;
string s[N], a;
int dp[N][N];
int n, m, k, res;

int edit_dist(string s, string a)
{
    int s_s = s.size(), a_s = a.size();
    for (int i = 0; i <= s_s; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= a_s; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= s_s; i++)
    {
        for (int j = 1; j <= a_s; j++)
        {
            if (s[i - 1] == a[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[s_s][a_s];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    while (m--)
    {
        cin >> a >> k;
        res = 0;
        for (int i = 0; i < n; i++)
        {
            if (edit_dist(s[i], a) <= k)
            {
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}