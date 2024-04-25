class Solution
{
private:
    int dinary(int left, int right, vector<int> &nums, int target)
    {
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }

public:
    int searchInsert(vector<int> &nums, int target)
    {
        int idx = dinary(0, nums.size() - 1, nums, target);
        return nums[idx] < target ? idx + 1 : idx;
    }
};