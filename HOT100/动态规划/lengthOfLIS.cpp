class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int mxlength = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            mxlength = max(mxlength, dp[i]);
        }
        return mxlength;
    }
};