class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> brackets;
        for (auto &chr : s)
        {
            if (chr == '(' || chr == '{' || chr == '[')
            {
                brackets.push(chr);
            }
            else
            {
                if (brackets.empty())
                {
                    return false;
                }
                auto tmp = brackets.top();
                brackets.pop();
                if (chr == ')' && tmp == '(')
                {
                    continue;
                }
                if (chr == ']' && tmp == '[')
                {
                    continue;
                }
                if (chr == '}' && tmp == '{')
                {
                    continue;
                }
                return false;
            }
        }
        return brackets.empty();
    }
};