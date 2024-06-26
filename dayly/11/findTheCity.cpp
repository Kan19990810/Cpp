class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        pair<int, int> ans(INT_MAX / 2, -1);
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> mp(n, vector<int>(n, INT_MAX / 2));
        for (auto &eg : edges)
        {
            int from = eg[0], to = eg[1], weight = eg[2];
            mp[from][to] = mp[to][from] = weight;
        }
        for (int i = 0; i < n; i++)
        {
            dis[i][i] = 0;
            for (int j = 0; j < n; j++)
            {
                int t = -1;
                for (int k = 0; k < n; k++)
                {
                    if (!vis[i][k] && (t == -1 || dis[i][k] < dis[i][t]))
                    {
                        t = k;
                    }
                }
                for (int k = 0; k < n; k++)
                {
                    dis[i][k] = min(dis[i][k], dis[i][t] + mp[t][k]);
                }
                vis[i][t] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }
            if (cnt <= ans.first)
            {
                ans = {cnt, i};
            }
        }
        return ans.second;
    }
};