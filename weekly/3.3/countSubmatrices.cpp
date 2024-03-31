class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + grid[i - 1][j - 1];
                if (s[i][j] <= k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};