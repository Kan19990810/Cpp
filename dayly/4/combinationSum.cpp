#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(int idx, int n, int cum, int target, vector<int> &candidates)
    {
        if (cum > target)
            return;

        if (idx == n)
        {
            if (cum == target)
                res.push_back(cur);
            return;
        }

        dfs(idx + 1, n, cum, target, candidates);
        cur.push_back(candidates[idx]);
        dfs(idx, n, cum + candidates[idx], target, candidates);
        cur.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        int n = candidates.size();
        dfs(0, n, 0, target, candidates);
        return res;
    }
};