#include <vector>

using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &ans, vector<int> &res, vector<int> &candidates, int target, int idx)
    {
        if (target < 0)
        {
            return;
        }

        if (target == 0)
        {
            ans.push_back(res);
            return;
        }

        if (idx == candidates.size())
        {
            return;
        }

        if (target - candidates[idx] >= 0)
        {
            res.push_back(candidates[idx]);
            dfs(ans, res, candidates, target - candidates[idx], idx);
            res.pop_back();
        }
        dfs(ans, res, candidates, target, idx + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> res;

        dfs(ans, res, candidates, target, 0);

        return ans;
    }
};