#include <vector>
using LL = long long;
class Solution
{
public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses, int k)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto &e : edges)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        unordered_set<LL> s;
        for (auto &e : guesses)
        {
            s.insert((LL)e[0] << 32 | e[1]);
        }

        int ans = 0, cnt0 = 0;

        function<void(int, int)> dfs = [&](int x, int fa)
        {
            for (int y : g[x])
            {
                if (y != fa)
                {
                    cnt0 += s.count((LL)x << 32 | y);
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        function<void(int, int, int)> reroot = [&](int x, int fa, int cnt)
        {
            ans += cnt >= k;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    reroot(y, x, cnt - s.count((LL)x << 32 | y) + s.count((LL)y << 32 | x));
                }
            }
        };
        reroot(0, -1, cnt0);
        return ans;
    }
};