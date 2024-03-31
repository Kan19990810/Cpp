class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int max_diag = 0;
        int ans = 0;
        for (auto &dimension : dimensions)
        {
            int length = dimension[0];
            int width = dimension[1];
            int diag = length * length + width * width;
            if (diag > max_diag)
            {
                max_diag = diag;
                ans = length * width;
            }
            if (diag == max_diag)
            {
                ans = max(ans, length * width);
            }
        }
        return ans;
    }
};