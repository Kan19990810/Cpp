class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j)
        {
            // i 越界
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        // i 从 0 开始对应"" 和 "a*" 匹配的情况
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (p[j - 1] == '*')
                {
                    // 初始化 - dp[i][j - 2] 匹配0个前面元素
                    dp[i][j] = dp[i][j] || dp[i][j - 2];
                    // s[i - 1] 和 p[j - 2]匹配
                    if (matches(i, j - 1))
                    {
                        // 转移dp[i - 1][j] 匹配多个前面元素
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }

                else
                {
                    if (matches(i, j))
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};