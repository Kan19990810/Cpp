class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 2)
        {
            return s;
        }

        int maxLength = 1;
        int begin = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n; i++)
            {
                int j = i + l - 1;
                if (j >= n)
                {
                    break;
                }

                if (s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else
                {
                    if (j - i <= 2)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if (dp[i][j] && j - i + 1 > maxLength)
                {
                    maxLength = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLength);
    }
};