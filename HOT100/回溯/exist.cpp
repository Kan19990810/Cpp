class Solution
{
private:
    bool valid;
    void dfs(int x, int y, int idx, vector<vector<int>> &pass, vector<vector<char>> &board, string word)
    {
        if (idx == word.size())
        {
            valid = true;
            return;
        }
        int n = board.size();
        int m = board[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i)
        {
            int tox = x + dx[i];
            int toy = y + dy[i];
            if (tox >= 0 && tox < n && toy >= 0 && toy < m)
            {
                if (!pass[tox][toy] && board[tox][toy] == word[idx])
                {
                    pass[tox][toy] = true;
                    dfs(tox, toy, idx + 1, pass, board, word);
                    pass[tox][toy] = false;
                }
            }
        }
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        valid = false;
        vector<vector<int>> pass(n, vector<int>(m, false));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == word[0])
                {
                    pass[i][j] = true;
                    dfs(i, j, 1, pass, board, word);
                    pass[i][j] = false;
                }
            }
        }
        return valid;
    }
};