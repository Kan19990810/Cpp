class Solution
{
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        // 记录以i为结束的收入
        vector<vector<pair<int, int>>> groups(n + 1);
        for (auto &ride : rides)
        {
            int start = ride[0], end = ride[1], tip = ride[2];
            groups[end].push_back({start, end - start + tip});
        }

        // 动态规划计算， i表示以i结尾的最高盈利
        vector<long long> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            for (auto &p : groups[i])
            {
                dp[i] = max(dp[i], dp[p.first] + p.second);
            }
        }
        return dp[n];
    }
};