class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        int m = wordDict.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                string chr = wordDict[j];
                if (i >= chr.size() && s.substr(i - chr.size(), chr.size()) == chr)
                {
                    dp[i] = dp[i] || dp[i - chr.size()];
                }
            }
        }
        return dp[n];
    }
};