class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        int ans = 0;
        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i - 1 >= 0 && dp[i - 1][j - 1] != -1 && grid[i][j] > grid[i - 1][j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                if (dp[i][j - 1] != -1 && grid[i][j] > grid[i][j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
                }
                if (i + 1 < n && dp[i + 1][j - 1] != -1 && grid[i][j] > grid[i + 1][j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};