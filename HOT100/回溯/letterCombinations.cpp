class Solution
{
private:
    unordered_map<char, string> chMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> ans;
    string res;
    void dfs(int idx, string &digits)
    {
        if (idx == digits.size())
        {
            if (res.size() > 0)
            {
                ans.push_back(res);
            }
            return;
        }

        string s = chMap[digits[idx]];
        for (auto ch : s)
        {
            res.push_back(ch);
            dfs(idx + 1, digits);
            res.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        dfs(0, digits);
        return ans;
    }
};