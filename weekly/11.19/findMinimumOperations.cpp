class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (s1[0] != s2[0] || s1[0] != s3[0])
        {
            return -1;
        }
        int i = 0;
        for (; i < n1 && i < n2 && i < n3; i++)
        {
            if (s1[i] != s2[i] || s1[i] != s3[i])
            {
                break;
            }
        }

        return n1 + n2 + n3 - 3 * i;
    }
};