class Solution
{
private:
    void dfs(vector<vector<int>> &ans, vector<int> &res, vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            ans.push_back(res);
            return;
        }

        dfs(ans, res, nums, idx + 1);

        res.push_back(nums[idx]);
        dfs(ans, res, nums, idx + 1);
        res.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> res = {};
        dfs(ans, res, nums, 0);
        return ans;
    }
};