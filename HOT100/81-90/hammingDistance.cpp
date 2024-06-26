class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int s = x ^ y, ret = 0;
        while (s)
        {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};
