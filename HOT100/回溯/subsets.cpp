class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(int idx, vector<int> &nums)
    {
        if (idx >= nums.size())
        {
            ans.push_back(res);
            return;
        }

        dfs(idx + 1, nums);
        res.push_back(nums[idx]);
        dfs(idx + 1, nums);
        res.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return ans;
    }
};