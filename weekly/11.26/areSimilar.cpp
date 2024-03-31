class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    if (j < k && mat[i][j] != mat[i][m + j - k])
                    {
                        return false;
                    }
                    if (j >= k && mat[i][j] != mat[i][j - k])
                    {
                        return false;
                    }
                }
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    if (j + k < m && mat[i][j] != mat[i][j + k])
                    {
                        return false;
                    }
                    if (j + k >= m && mat[i][j] != mat[i][j + k - m])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};