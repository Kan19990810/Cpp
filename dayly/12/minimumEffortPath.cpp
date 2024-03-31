class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        static const int INF = 1E9 + 9;
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INF));
        vector<vector<bool>> pass(r, vector<bool>(c, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        q.push({0, {0, 0}});
        while (!q.empty())
        {
            auto next_point = q.top();
            q.pop();
            int d = next_point.first;
            int x = next_point.second.first, y = next_point.second.second;
            if (pass[x][y])
            {
                continue;
            }
            pass[x][y] = true;
            dist[x][y] = d;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx <= r - 1 && ny >= 0 && ny <= c - 1 && !pass[nx][ny])
                {
                    q.push({max(d, abs(heights[x][y] - heights[nx][ny])), {nx, ny}});
                }
            }
        }
        return dist[r - 1][c - 1];
    }
};