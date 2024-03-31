class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        static const int MOD = 1e9 + 7;
        vector<vector<long long>> g(n, vector<long long>(n, LLONG_MAX / 2));
        for (auto &r : roads)
        {
            int x = r[0];
            int y = r[1];
            int d = r[2];
            g[x][y] = d;
            g[y][x] = d;
        }

        // 记录是否经过
        vector<bool> st(n, false);
        // 记录0到点的距离
        vector<long long> dis(n, LLONG_MAX / 2);
        // 记录到点的方案数
        vector<int> f(n, 0);

        dis[0] = 0;
        f[0] = 1;

        while (true)
        {
            // 选择一个未选中的最短距离点
            int x = -1;
            for (int i = 0; i < n; i++)
            {
                if (!st[i] && (x < 0 || dis[i] < dis[x]))
                {
                    x = i;
                }
            }
            // 选择点为 n-1则为结束条件
            if (x == n - 1)
            {
                return f[n - 1];
            }
            st[x] = true;

            // 由选择的点更新其他点的距离
            for (int y = 0; y < n; y++)
            {
                long long new_dis = dis[x] + g[x][y];
                // 如果dis[y] > new_dis 最短路径中 x, y 为同一路径
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    f[y] = f[x];
                }
                // 如果dis[y] = new_dis 最短路径中 y 可以经过x点和另外一点
                else if (new_dis == dis[y])
                {
                    f[y] = (f[y] + f[x]) % MOD;
                }
            }
        }
    }
};