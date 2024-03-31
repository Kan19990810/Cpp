class Solution
{
private:
    void quick_sort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int x = nums[(left + right) >> 1];
        int i = left - 1, j = right + 1;
        while (i < j)
        {
            do
                i++;
            while (nums[i] < x);
            do
                j--;
            while (nums[j] > x);
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(nums, left, j);
        quick_sort(nums, j + 1, right);
    }

public:
    void sortColors(vector<int> &nums)
    {
        // 递归
        quick_sort(nums, 0, nums.size() - 1);
        return;
    }
};