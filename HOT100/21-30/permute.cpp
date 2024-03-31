class Solution
{
private:
    void dfs(vector<vector<int>> &ans, vector<int> &res, vector<bool> &st, vector<int> &nums)
    {
        if (res.size() == nums.size())
        {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!st[i])
            {
                st[i] = true;
                res.push_back(nums[i]);
                dfs(ans, res, st, nums);
                res.pop_back();
                st[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> st(n, false);

        dfs(ans, res, st, nums);

        return ans;
    }
};