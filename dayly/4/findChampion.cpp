class Solution
{
public:
    int findChampion(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            int cum = 0;
            for (int j = 0; j < grid[i].size(); j++)
            {
                cum += grid[i][j];
            }
            if (cum == grid.size() - 1)
            {
                return i;
            }
        }
        return 0;
    }
};