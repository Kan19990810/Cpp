class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &nums)
    {
        // 单调递增栈 栈顶大于元素则弹出， 弹出元素右侧小于的最近元素为新元素， 栈顶元素为新元素左侧小于元素的最近元素
        // 单调递减栈 栈顶小于新元素则弹出， 弹出元素右侧大于的最近元素为新元素， 栈顶元素为新元素左侧大于元素的最近元素
        // 右侧的下下个更大元素  两重单调递减栈
        int n = nums.size();
        vector<int> ans(n, -1), s, t;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            // 二重单调栈， 弹出元素右侧大大最近元素为x
            while (!t.empty() && nums[t.back()] < x)
            {
                ans[t.back()] = x;
                t.pop_back();
            }
            // 一重单调栈，弹出元素右侧大最近元素为x
            // 一重单调栈弹出元素应该原封不动给二重单调栈
            int j = s.size();
            while (j && nums[s[j - 1]] < x)
            {
                j--;
            }
            t.insert(t.end(), s.begin() + j, s.end());
            s.resize(j);
            s.push_back(i);
        }
        return ans;
    }
};