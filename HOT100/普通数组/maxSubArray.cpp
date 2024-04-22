class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN, cum = 0;
        for (int right = 0; right < n; ++right)
        {
            cum += nums[right];
            ans = max(ans, cum);
            if (cum < 0)
            {
                cum = 0;
            }
        }
        return ans;
    }
};