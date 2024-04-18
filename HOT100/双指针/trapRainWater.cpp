#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n = heightMap.size();
        int m = heightMap[0].size();
        if (n <= 2 || m <= 2)
        {
            return 0;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    pq.push({heightMap[i][j], i * m + j});
                    visit[i][j] = true;
                }
            }
        }

        int ans = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            int currH = curr.first;
            for (int i = 0; i < 4; i++)
            {
                int tx = curr.second / m + dx[i];
                int ty = curr.second % m + dy[i];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m && !visit[tx][ty])
                {
                    if (heightMap[tx][ty] < currH)
                    {
                        ans += currH - heightMap[tx][ty];
                    }
                    visit[tx][ty] = true;
                    pq.push({max(heightMap[tx][ty], currH), tx * m + ty});
                }
            }
        }

        return ans;
    }
};