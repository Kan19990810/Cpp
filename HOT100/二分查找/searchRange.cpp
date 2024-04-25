class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        int ansleft = right;
        left = 0, right = nums.size() - 1;
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
        int ansright = right;
        if (nums[ansleft] == target)
        {
            return {ansleft, ansright};
        }
        return {-1, -1};
    }
};