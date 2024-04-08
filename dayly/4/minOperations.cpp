class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());

        vector<int> precum(n, 0);
        for (int i = 1; i < n; i++)
        {
            precum[i] = precum[i - 1];
            if (nums[i] == nums[i - 1])
            {
                precum[i]++;
            }
        }

        int ans = n;
        for (int i = 0; i < n; i++)
        {
            int target = nums[i] + n - 1;
            // 找到小于等于target的第一个数
            int left = i, right = n - 1;
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
            // cout << "nums[i]:" << nums[i] << " target:" << target << " nums[left]:" << nums[left] << " n-right+i-1" << n - right + i - 1 << endl;
            int res = n - right + i - 1 + precum[right] - precum[i];
            ans = min(ans, res);
        }
        return ans;
    }
};