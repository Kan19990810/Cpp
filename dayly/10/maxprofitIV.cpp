class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int f[n][3];

        f[0][0] = -prices[0];

        for (int i = 1; i < n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
    }
    return max(f[n - 1][1], f[n - 1][2]);
};