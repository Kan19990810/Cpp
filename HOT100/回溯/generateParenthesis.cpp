class Solution
{
private:
    vector<string> ans;
    string res;
    void dfs(int idx, int n)
    {
        if (idx == n)
        {
            if (isValid(res))
            {
                ans.push_back(res);
            }
            return;
        }

        res.push_back('(');
        dfs(idx + 1, n);
        res.pop_back();
        res.push_back(')');
        dfs(idx + 1, n);
        res.pop_back();
    }

    bool isValid(string str)
    {
        int left = 0;
        int right = 0;
        for (auto ch : str)
        {
            if (ch == '(')
            {
                left++;
            }
            if (ch == ')')
            {
                right++;
            }

            if (left < right)
            {
                return false;
            }
        }
        return left == right;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(0, 2 * n);
        return ans;
    }
};