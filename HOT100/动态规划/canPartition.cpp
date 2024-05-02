class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int cum = accumulate(nums.begin(), nums.end(), 0);
        if (cum % 2 == 1)
        {
            return false;
        }

        vector<bool> dp(cum / 2 + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = cum / 2; j >= 0; j--)
            {
                if (j >= nums[i] && dp[j - nums[i]])
                {
                    dp[j] = true;
                }
            }
        }
        return dp[cum / 2];
    }
};