class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int x = 0, y = -1;
        int disC = n - 1, disR = m;
        vector<int> ans;
        while (true)
        {

            if (!disR)
            {
                break;
            }

            for (int i = 0; i < disR; ++i)
            {
                y++;
                ans.push_back(matrix[x][y]);
            }
            disR--;

            if (!disC)
            {
                break;
            }

            for (int i = 0; i < disC; ++i)
            {
                x++;
                ans.push_back(matrix[x][y]);
            }
            disC--;

            if (!disR)
            {
                break;
            }

            for (int i = 0; i < disR; ++i)
            {
                y--;
                ans.push_back(matrix[x][y]);
            }
            disR--;

            if (!disC)
            {
                break;
            }

            for (int i = 0; i < disC; ++i)
            {
                x--;
                ans.push_back(matrix[x][y]);
            }
            disC--;
        }
        return ans;
    }
};