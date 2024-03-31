class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 前缀乘积和后缀乘积
        int n = nums.size();
        vector<int> pre(n + 1, 1);
        vector<int> rev(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
            rev[i] = rev[i - 1] * nums[n - i];
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = pre[i] * rev[n - i - 1];
        }
        return ans;
    }
};