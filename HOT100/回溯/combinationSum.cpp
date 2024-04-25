class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(int idx, vector<int> &candidates, int cur, int target)
    {
        if (idx == candidates.size())
        {
            if (cur == target)
            {
                ans.push_back(res);
            }
            return;
        }

        if (cur > target)
        {
            return;
        }

        dfs(idx + 1, candidates, cur, target);

        res.push_back(candidates[idx]);
        dfs(idx, candidates, cur + candidates[idx], target);
        res.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        dfs(0, candidates, 0, target);
        return ans;
    }
};