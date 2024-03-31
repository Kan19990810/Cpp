class Solution
{
public:
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        vector<vector<int>> g(roads.size() + 1);
        for (auto &e : roads)
        {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        long long ans = 0;

        function<int(int, int)> dfs = [&](int x, int fa) -> int
        {
            int size = 1;
            for (int y : g[x])
            {
                if (y != fa)
                {
                    size += dfs(y, x);
                }
            }
            if (x)
            {
                ans += (size - 1) / seats + 1;
            }
            return size;
        };
        dfs(0, -1);
        return ans;
    }
};