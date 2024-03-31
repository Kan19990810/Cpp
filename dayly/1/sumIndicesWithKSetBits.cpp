class Solution
{
public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int j = i, c = 0;
            while (j)
            {
                c += j % 2;
                j /= 2;
            }
            if (c == k)
            {
                ans += nums[i];
            }
        }
        return ans;
    }
};