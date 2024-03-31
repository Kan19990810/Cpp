class Solution
{
public:
    int addMinimum(string word)
    {
        int n = word.size();
        vector<int> dp(n + 1);
        dp[0] = 2;
        for (int i = 1; i < n; ++i)
        {
            auto &pre = word[i - 1];
            auto &cur = word[i];
            if (cur == 'a')
            {
                dp[i] = dp[i - 1] + 2;
            }
            if (cur == 'b')
            {
                if (pre == 'a')
                {
                    dp[i] = dp[i - 1] - 1;
                }
                else
                {
                    dp[i] = dp[i - 1] + 2;
                }
            }
            if (cur == 'c')
            {
                if (pre == 'a' || pre == 'b')
                {
                    dp[i] = dp[i - 1] - 1;
                }
                else
                {
                    dp[i] = dp[i - 1] + 2;
                }
            }
        }
        return dp[n - 1];
    }
};