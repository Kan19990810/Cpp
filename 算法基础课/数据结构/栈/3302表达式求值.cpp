#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<int> op;

int main()
{
    unordered_map<char, int> pr{{"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}};
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i ++ )
    {
        auto c = str[i];
        if(isdigit(c))
        {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
            {
                x = x * 10 + str[j ++] - '0';
            }
            num.push(x);
        }
        else if (c == '(') op.push(c);
        else if (c == ')')
        {
            while (op.top() != '(') eval();
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c]) eval();
        }
    }
}