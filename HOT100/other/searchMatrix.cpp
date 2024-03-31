class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low < high)
        {
            int mid = (low + high) >> 1;
            int x = matrix[mid / n][mid % n];
            if (x >= target)
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return matrix[high / n][high % n] == target;
    }
};
