class Solution
{
public:
    long long minimumSteps(string s)
    {
        long long res = 0;
        long long w = 0;
        for (auto str : s)
        {
            if (str == '1')
            {
                w++;
            }
            else
            {
                res += w;
            }
        }
        return res;
    }
};