class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!q.empty())
        {
            time++;
            int k = q.size();
            while (k--)
            {
                auto tmp = q.front();
                q.pop();
                int x = tmp.first;
                int y = tmp.second;
                for (int i = 0; i < 4; ++i)
                {
                    int tox = x + dx[i];
                    int toy = y + dy[i];

                    if (tox >= 0 && tox < n && toy >= 0 && toy < m)
                    {
                        if (grid[tox][toy] == 1)
                        {
                            grid[tox][toy] = 2;
                            q.push({tox, toy});
                        }
                    }
                }
            }
        }
        bool isValid = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    isValid = false;
                }
            }
        }

        return isValid ? time : -1;
    }
};