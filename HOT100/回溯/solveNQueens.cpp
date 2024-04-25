class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> res;

    void dfs(int row, int n, vector<bool> &col, vector<bool> &dia, vector<bool> &redia)
    {
        if (row == n)
        {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (!col[i] && !dia[row - i + n] && !redia[row + i])
            {
                col[i] = dia[row - i + n] = redia[row + i] = true;
                res[row][i] = 'Q';
                dfs(row + 1, n, col, dia, redia);
                col[i] = dia[row - i + n] = redia[row + i] = false;
                res[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        res = vector<string>(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> dia(2 * n, false);
        vector<bool> redia(2 * n, false);
        dfs(0, n, col, dia, redia);
        return ans;
    }
};