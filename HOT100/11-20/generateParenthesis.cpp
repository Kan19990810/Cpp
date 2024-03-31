class Solution
{
private:
    void dfs(int n, vector<string> &ans, string &res, int left, int right)
    {
        if (res.size() == 2 * n)
        {
            ans.push_back(res);
            return;
        }

        // 放右括号的情况
        if (left > right)
        {
            res.push_back(')');
            dfs(n, ans, res, left, right + 1);
            res.pop_back();
        }
        // 放左括号的情况
        if (left == right || (left > right && left < n))
        {
            res.push_back('(');
            dfs(n, ans, res, left + 1, right);
            res.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string res = "";
        dfs(n, ans, res, 0, 0);
        return ans;
    }
};