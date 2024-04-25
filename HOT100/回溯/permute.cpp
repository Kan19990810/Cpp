class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(int idx, int n, vector<bool> &isChoose, vector<int> &nums)
    {
        if (idx == n)
        {
            ans.push_back(res);
        }

        for (int i = 0; i < n; ++i)
        {
            if (!isChoose[i])
            {
                isChoose[i] = true;
                res.push_back(nums[i]);
                dfs(idx + 1, n, isChoose, nums);
                res.pop_back();
                isChoose[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> isChoose(n);
        dfs(0, n, isChoose, nums);
        return ans;
    }
};