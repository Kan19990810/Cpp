class Solution
{
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> g(n);

        vector<int> dis(n, 0);
        vector<int> side(n, 0);
        vector<int> side_cnt(n, 0);

        vector<int> cnt(n, 0);

        for (auto &edge : edges)
        {
            int x = edge[0];
            int y = edge[1];
            int d = edge[2];
            g[x].push_back({y, d});
            g[y].push_back({x, d});
        }

        int idx = 0;
        function<void(int root, int x, int fa)> dfs = [&](int root, int x, int fa)
        {
            for (auto &t : g[x])
            {
                int y = t.first;
                int d = t.second;
                if (y != fa)
                {
                    // 标记root的分路
                    if (root == x)
                    {
                        side[y] = idx++;
                        dis[y] = d % signalSpeed;
                    }
                    // 和父节点同一分路
                    else
                    {
                        side[y] = side[x];
                        dis[y] = (dis[x] + d) % signalSpeed;
                    }

                    if (dis[y] == 0)
                    {
                        side_cnt[side[y]]++;
                    }
                    dfs(root, y, x);
                }
            }
        };

        // 根节点到每个点的位置知道了
        // 问题在于分边

        for (int i = 0; i < n; i++)
        {
            fill(dis.begin(), dis.end(), 0);
            fill(side.begin(), side.end(), 0);
            fill(side_cnt.begin(), side_cnt.end(), 0);
            idx = 0;
            dfs(i, i, -1);
            // 遍历分路
            int i_cnt = 0;
            int cum = 0;
            for (auto &t : g[i])
            {
                int y = t.first;
                i_cnt += cum * side_cnt[side[y]];
                cum += side_cnt[side[y]];
                cout << i << ' ' << y << ' ' << cum << ' ' << side[y] << ' ' << side_cnt[side[y]] << ' ' << i_cnt << endl;
            }
            cnt[i] = i_cnt;
        }
        return cnt;
    }
};