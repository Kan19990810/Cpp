class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > 0)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        int posNum = n - right;

        if (nums[right] == 0)
        {
            posNum = 0;
        }
        left = 0, right = n - 1;
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            if (nums[mid] < 0)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }

        int negNum = right + 1;
        if (nums[right] == 0)
        {
            negNum = 0;
        }
        return max(posNum, negNum);
    }
};