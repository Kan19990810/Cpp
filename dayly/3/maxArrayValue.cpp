class Solution
{
public:
    long long maxArrayValue(vector<int> &nums)
    {
        int n = nums.size();
        long long maxans = nums[n - 1];
        long long cur = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] <= cur)
            {
                cur += nums[i];
                maxans = max(cur, maxans);
            }
            else
            {
                cur = nums[i];
                maxans = max(cur, maxans);
            }
        }
        return maxans;
    }
};