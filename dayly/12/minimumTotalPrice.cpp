class Solution
{
public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
    {
        // 构造邻接表
        vector<vector<int>> g(n);
        for (auto &edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // 深度优先 ，纪录每个节点的经过次数
        vector<int> count_p(n);

        function<bool(int, int, int)> dfs = [&](int start, int end, int fa) -> bool
        {
            if (start == end)
            {
                count_p[start]++;
                return true;
            }

            for (auto &to_p : g[start])
            {
                if (to_p != fa && dfs(to_p, end, start))
                {
                    count_p[start]++;
                    return true;
                }
            }
            return false;
        };

        for (auto &trip : trips)
        {
            int s = trip[0], e = trip[1];
            dfs(s, e, -1);
        }

        // 树形动态规划，非相邻节点的总价格

        function<pair<int, int>(int, int)> tree_dy = [&](int x, int fa) -> pair<int, int>
        {
            int not_halve = price[x] * count_p[x];
            int halve = not_halve / 2;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    auto [nh, h] = tree_dy(y, x);
                    not_halve += min(nh, h);
                    halve += nh;
                }
            }
            return {not_halve, halve};
        };
        auto [nh, h] = tree_dy(0, -1);
        return min(nh, h);
    }
};