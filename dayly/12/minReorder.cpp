class Solution
{
public:
    // 深度优先遍历，纪录改变方向数；
    int dfs(int x, int fa, vector<vector<pair<int, int>>> &g)
    {
        int res = 0;
        for (auto &edge : g[x])
        {
            if (edge.first == fa)
            {
                continue;
            }
            res += edge.second + dfs(edge.first, x, g);
        }
        return res;
    }

    int minReorder(int n, vector<vector<int>> &connections)
    {
        // 构建邻接图
        vector<vector<pair<int, int>>> g(n);
        for (auto &connection : connections)
        {
            g[connection[0]].push_back({connection[1], 1});
            g[connection[1]].push_back({connection[0], 0});
        }
        return dfs(0, -1, g);
    }
};