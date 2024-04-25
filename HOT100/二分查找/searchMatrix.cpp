class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = n * m - 1;
        while (left < right)
        {
            int mid = (left + right) >> 1;
            int x = mid / m;
            int y = mid % m;
            if (matrix[x][y] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        int x = right / m;
        int y = right % m;
        if (matrix[x][y] == target)
        {
            return true;
        }
        return false;
    }
};