class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int maxIdx = max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin();
            if (mat[mid][maxIdx] > mat[mid + 1][maxIdx])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        int idx = max_element(mat[l].begin(), mat[l].end()) - mat[l].begin();
        return {l, idx};
    }
};