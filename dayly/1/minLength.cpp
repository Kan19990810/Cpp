class Solution
{
public:
    int minLength(string s)
    {
        int n = s.size();
        stack<char> strStack;
        for (int i = 0; i < n; ++i)
        {
            auto t = strStack.top();
            if (!strStack.empty() && ((t == 'A' && s[i] == 'B') || (t == 'C' && s[i] == 'D')))
            {
                strStack.pop();
            }
            else
            {
                strStack.push(s[i]);
            }
        }
        return strStack.size();
    }
};