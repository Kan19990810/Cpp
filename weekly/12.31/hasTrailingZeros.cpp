class Solution
{
public:
    bool hasTrailingZeros(vector<int> &nums)
    {
        int ans = 0;
        for (auto &num : nums)
        {
            if (num % 2 == 0)
            {
                ans++;
            }
            if (ans == 2)
            {
                return true;
            }
        }
        return false;
    }
};