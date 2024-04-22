#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int>> ans;
    vector<int> res;
    void dfs(int index, int num, int k, int cur, int n)
    {
        if (index >= 10)
        {
            return;
        }

        if (cur > n)
        {
            return;
        }

        if (num == k)
        {
            if (cur == n)
            {
                ans.push_back(res);
            }
            return;
        }

        for (int i = index + 1; i <= 9; ++i)
        {
            res.push_back(i);
            dfs(i, num + 1, k, cur + i, n);
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(0, 0, k, 0, n);
        return ans;
    }
};