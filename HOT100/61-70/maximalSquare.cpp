class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    ans = max(ans, dp[i][j] * dp[i][j]);
                    // cout << "i:" << i << " j:" << j << " matrix[i - 1][j - 1]:" << matrix[i - 1][j - 1] << " ans:" << ans << endl;
                }
            }
        }
        return ans;
    }
};