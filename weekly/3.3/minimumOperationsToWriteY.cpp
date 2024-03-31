class Solution
{
public:
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int mid = n / 2;
        vector<int> y_cnt(3, 0);
        vector<int> other_cnt(3, 0);
        int y_num = 0;
        int other_num = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i <= mid && i == j)
                {
                    int tmp = grid[i][j];
                    y_cnt[tmp]++;
                    y_num++;
                    continue;
                }
                if (i <= mid && i + j == 2 * mid)
                {
                    int tmp = grid[i][j];
                    y_cnt[tmp]++;
                    y_num++;
                    continue;
                }
                if (i >= mid && j == mid)
                {
                    int tmp = grid[i][j];
                    y_cnt[tmp]++;
                    y_num++;
                    continue;
                }
                int tmp = grid[i][j];
                other_cnt[tmp]++;
                other_num++;
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            int tmp = y_num - y_cnt[i] + other_num - max(other_cnt[(i + 1) % 3], other_cnt[(i + 2) % 3]);
            ans = min(ans, tmp);
        }
        return ans;
    }
};