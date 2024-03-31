class Solution
{
public:
    vector<int> divisibilityArray(string word, int m)
    {
        int n = word.size();
        vector<int> ans(n, 0);
        long long cum = 0;
        for (int i = 0; i < n; i++)
        {
            cum = (long long)cum * 10 + word[i] - '0';
            cum %= m;
            if (cum == 0)
            {
                ans[i] = 1;
            }
        }
        return ans;
    }
};