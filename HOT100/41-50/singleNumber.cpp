class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 异或0为本身，异或本身为0
        int ret = 0;
        for (auto num : nums)
            ret ^= num;
        return ret;
    }
};