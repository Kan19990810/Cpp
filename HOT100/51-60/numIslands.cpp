class Solution
{
private:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
        for (int t = 0; t < 4; t++)
        {
            int x = i + dx[t], y = j + dy[t];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
            {
                dfs(grid, x, y);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};