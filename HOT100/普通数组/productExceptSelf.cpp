class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n + 1, 1);
        vector<int> suf(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
            suf[i] = suf[i - 1] * nums[n - i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = pre[i] * suf[n - i - 1];
        }
        return ans;
    }
};