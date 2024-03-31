class Solution
{
public:
    long long sellingWood(int m, int n, vector<vector<int>> &prices)
    {
        vector<vector<int>> pr(m + 1, vector<int>(n + 1));
        for (auto &p : prices)
        {
            pr[p[0]][p[1]] = p[2];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = pr[i][j];
                for (int k = 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k]);
                for (int k = 1; k < i; k++)
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
        }
        return dp[m][n];
    }
};