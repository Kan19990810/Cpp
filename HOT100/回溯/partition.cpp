class Solution
{
private:
    vector<vector<string>> ans;
    vector<string> res;

    void dfs(int idx, string s)
    {
        if (idx == s.size())
        {
            ans.push_back(res);
            return;
        }

        for (int i = idx; i < s.size(); ++i)
        {

            string str = s.substr(idx, i - idx + 1);
            if (isvalid(str))
            {
                res.push_back(str);
                dfs(i + 1, s);
                res.pop_back();
            }
        }
    }

    bool isvalid(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s)
    {
        dfs(0, s);
        return ans;
    }
};