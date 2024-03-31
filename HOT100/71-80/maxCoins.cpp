class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> val(n + 2);
        for (int i = 0; i < n; i++)
        {
            val[i + 1] = nums[i];
        }
        val[0] = 1;
        val[n + 1] = 1;

        for (int l = 3; l <= n + 2; l++)
        {
            for (int i = 0; i + l - 1 < n + 2; i++)
            {
                int j = i + l - 1;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], val[k] * val[i] * val[j] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};