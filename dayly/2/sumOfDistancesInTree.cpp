#include <vector>
class Solution
{
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> ans(n);
        vector<int> size(n, 1);
        // 统计子树节点数
        function<void(int, int, int)> dfs = [&](int x, int fa, int depth)
        {
            ans[0] += depth;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    // 状态转移 先知道子节点数量 -> 根节点数量
                    // 从叶子节点到根节点
                    dfs(y, x, depth + 1);
                    size[x] += size[y];
                }
            }
        };
        dfs(0, -1, 0);

        // 换根DP
        function<void(int, int)> reroot = [&](int x, int fa)
        {
            for (int y : g[x])
            {
                if (y != fa)
                {
                    // 状态转移 先知道根节点距离 -> 子节点距离
                    // 从根节点到叶子节点
                    ans[y] = ans[x] + n - 2 * size[y];
                    reroot(y, x);
                }
            }
        };
        reroot(0, -1);
        return ans;
    }
};