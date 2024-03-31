#include <vector>

class Solution
{
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<bool> r(n, false);
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (auto &res : restricted)
        {
            r[res] = true;
        }

        int ans = 1;
        function<void(int root, int fa)> dfs = [&](int root, int fa)
        {
            for (auto &y : g[root])
            {
                if (y != fa && !r[y])
                {
                    ans++;
                    dfs(y, root);
                }
            }
        };

        dfs(0, -1);
        return ans;
    }
};