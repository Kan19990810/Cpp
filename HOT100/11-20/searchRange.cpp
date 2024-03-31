class Solution
{
private:
    int binarySearch(vector<int> &nums, int target)
    {
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
        return left;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        int lowerBound = binarySearch(nums, target);
        int higherBound = binarySearch(nums, target + 1);
        if (nums[lowerBound] != target)
        {
            return {-1, -1};
        }
        if (nums[higherBound] != target)
        {
            return {lowerBound, higherBound - 1};
        }
        return {lowerBound, higherBound};
    }
};