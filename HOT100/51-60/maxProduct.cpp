class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); i++)
        {
            maxF[i] = max(nums[i], max(maxF[i - 1] * nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(nums[i], min(maxF[i - 1] * nums[i], minF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};