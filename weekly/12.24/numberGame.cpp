class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i = i + 2)
        {
            ans[i] = nums[i + 1];
            ans[i + 1] = nums[i];
        }
        return ans;
    }
};