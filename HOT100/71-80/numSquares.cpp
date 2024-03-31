class Solution
{
public:
    int numSquares(int n)
    {

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j]);
            }
            dp[i] += 1;
            // cout << i << ' ' << dp[i] << endl;
        }
        return dp[n];
    }
};