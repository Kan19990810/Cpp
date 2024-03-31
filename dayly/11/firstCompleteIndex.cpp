class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        // 纪录行列涂的个数， map
        // 快速查找涂的位置 map
        static const int N = 1e5 + 7;
        pair<int, int> pos[N];
        int col[N]{0}, row[N]{0};
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int t = mat[i][j];
                pos[t] = {i, j};
                // cout << t <<' '<< pos[t].first<<' ' << pos[t].second<<endl;
            }
        }
        // cout << n << ' ' <<m <<endl;
        for (int i = 0; i < arr.size(); i++)
        {
            int r = pos[arr[i]].first, c = pos[arr[i]].second;
            col[c]++;
            row[r]++;
            // cout << i <<' ' << r <<' ' << c <<' ' << row[r] <<' ' << col[r]<<endl;
            if (row[r] == m || col[c] == n)
            {
                return i;
            }
        }
        return -1;
    }
};