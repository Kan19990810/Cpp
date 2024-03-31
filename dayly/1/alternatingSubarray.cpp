class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int ans = -1;
        int i = 0, n = nums.size();
        while (i < n - 1)
        {
            // 起始位置
            if (nums[i + 1] - nums[i] != 1)
            {
                i++;
                continue;
            }
            int i0 = i;
            i += 2;
            // 终点位置
            while (i < n && nums[i] == nums[i0] + (i - i0) % 2)
            {
                i++;
            }
            ans = max(ans, i - i0);
            // 回退
            i--;
        }
        return ans;
    }
};