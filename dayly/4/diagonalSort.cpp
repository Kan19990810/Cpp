class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> a(min(m, n));
        for (int k = 1 - n; k < m; k++)
        { // k = i - j
            int left_i = max(k, 0), right_i = min(k + n, m);
            for (int i = left_i; i < right_i; i++)
            {
                a[i - left_i] = mat[i][i - k];
            }
            sort(a.begin(), a.begin() + (right_i - left_i));
            for (int i = left_i; i < right_i; i++)
            {
                mat[i][i - k] = a[i - left_i];
            }
        }
        return mat;
    }
};
