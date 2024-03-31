class Solution
{
public:
    long long countSubstrings(string s, char c)
    {
        long long ans = 0;
        long long cum = 0;
        for (auto chr : s)
        {
            if (chr == c)
            {
                cum++;
                ans += cum;
            }
        }
        return ans;
    }
};