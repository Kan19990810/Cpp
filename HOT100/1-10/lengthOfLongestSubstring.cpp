class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> char_set;
        int ans = 0;
        int n = s.size();
        for (int i = 0, j = 0; i < n; i++)
        {
            while (char_set.count(s[i]))
            {
                char_set.erase(s[j++]);
            }
            char_set.emplace(s[i]);
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};