class Solution
{
public:
    bool isSubstringPresent(string s)
    {
        string res = s;
        reverse(res.begin(), res.end());

        int n = s.size();

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (s[i] == res[j] && s[i + 1] == res[j + 1])
                {
                    return true;
                }
            }
        }
        return false;
    }
};
