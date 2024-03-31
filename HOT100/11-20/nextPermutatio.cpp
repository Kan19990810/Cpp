class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size() - 2;
        while (n >= 0 && nums[n] >= nums[n + 1])
        {
            n--;
        }
        if (n >= 0)
        {
            int j = nums.size() - 1;
            while (j >= 0 && nums[n] >= nums[j])
            {
                j--;
            }
            swap(nums[n], nums[j]);
        }
        reverse(nums.begin() + n + 1, nums.end());
    }
};