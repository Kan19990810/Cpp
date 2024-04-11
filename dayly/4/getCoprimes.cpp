#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges)
    {
        int n = nums.size();
        init();
        g.resize(n);
        ans.resize(n, -1);
        for (auto edge : edges)
        {
            int x = edge[0], y = edge[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0, -1, 1, nums);
        return ans;
    }

    void init()
    {
        coprime.resize(51);
        valDepthId.resize(51);
        for (int i = 1; i < 51; i++)
        {
            for (int j = 1; j < 51; j++)
            {
                if (gcd(i, j) == 1)
                {
                    coprime[i].push_back(j);
                }
            }
        }
        return;
    }

    void dfs(int x, int fa, int depth, vector<int> &nums)
    {
        int val = nums[x];
        int max_depth = 0;
        for (int j : coprime[val])
        {
            auto [depth, id] = valDepthId[j];
            if (depth > max_depth)
            {
                max_depth = depth;
                ans[x] = id;
            }
        }

        // 深度有限遍历，其中记住祖先节点的深度和id
        auto tmp = valDepthId[val];
        valDepthId[val] = {depth, x};
        for (int y : g[x])
        {
            if (y != fa)
            {
                dfs(y, x, depth + 1, nums);
            }
        }
        valDepthId[val] = tmp;
    }

private:
    vector<vector<int>> coprime;
    vector<pair<int, int>> valDepthId;
    vector<vector<int>> g;
    vector<int> ans;
};