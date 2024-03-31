class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int n = s.size();
        string ans = s;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] < s[n - 1 - i])
            {
                ans[n - 1 - i] = s[i];
            }
            else
            {
                ans[i] = s[n - 1 - i];
            }
        }
        return ans;
    }
};