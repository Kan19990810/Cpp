class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int num_vow = 0;
            int num_cons = 0;
            for (int j = i; j < n; j++)
            {
                if (vowels.count(s[j]) > 0)
                {
                    num_vow++;
                }
                else
                {
                    num_cons++;
                }
                if (num_cons == num_vow && (num_cons * num_vow) % k == 0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};