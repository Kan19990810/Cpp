class Solution
{
public:
    bool possibleToStamp(vector<vector<int>> &grid, int stampHeight, int stampWidth)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> s(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + grid[i][j];
            }
        }

        vector<vector<int>> d(m + 2, vector<int>(n + 2));
        for (int i = stampHeight; i <= m; i++)
        {
            for (int j = stampWidth; j <= n; j++)
            {
                int i1 = i - stampHeight + 1;
                int j1 = j - stampWidth + 1;
                if (s[i][j] - s[i][j1 - 1] - s[i1 - 1][j] + s[i1 - 1][j1 - 1] == 0)
                {
                    d[i1][j1]++;
                    d[i1][j + 1]--;
                    d[i + 1][j1]--;
                    d[i][j]++;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
                if (grid[i][j] == 0 && d[i + 1][j + 1] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};