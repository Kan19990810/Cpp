class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (!nums.size())
        {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            // if (nums[mid] == target)
            // {
            //     return mid;
            // }

            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target <= nums[mid])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] >= target || target > nums[nums.size() - 1])
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return nums[right] == target ? right : -1;
    }
};