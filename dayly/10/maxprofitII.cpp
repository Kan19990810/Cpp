class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][4];

        dp[0][0] = -prices[0], dp[0][2] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(- prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i][0] + prices[i], dp[i - 1][1]);
            dp[i][2] = max(dp[i][1] - prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i][2] + prices[i], dp[i - 1][3]);
        }
        return dp[n - 1][3];
    }
};