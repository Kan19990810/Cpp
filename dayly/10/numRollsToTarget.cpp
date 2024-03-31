class Solution
{
public:
    int numRollsToTarget(int n, int k, int target)
    {
        // 动态规划 f[i][j] 为第i个骰子到j的方式
        // f[i][j] = f[i - 1][j - 1] + ... + f[i - 1][j - k]

        const int mod = 1e9 + 7;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 1; i <= k && i <= target; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                for (int t = 1; t <= k && j - t >= 0; t++)
                {
                    dp[i][j] += dp[i - 1][j - t];
                    dp[i][j] %= mod;
                }
            }
        }

        return dp[n][target];
    }
};