class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = n - 1, y = 0;
        while (x >= 0 && y < m)
        {
            int num = matrix[x][y];
            if (num == target)
            {
                return true;
            }

            if (num > target)
            {
                x--;
            }
            else
            {
                y++;
            }
        }
        return false;
    }
};