#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

stack<int> num;
stack<char> op;

void eval()
{
    int x;
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char c = op.top();
    op.pop();
    if (c == '+')
    {
        x = a + b;
    }
    else if (c == '-')
    {
        x = a - b;
    }
    else if (c == '*')
    {
        x = a * b;
    }
    else
    {
        x = a / b;
    }
    num.push(x);
}

int main()
{
    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (isdigit(c))
        {
            int x = 0, j = i;
            while (isdigit(str[j]) && j < str.size())
            {
                x = x * 10 + str[j++] - '0';
            }
            num.push(x);
            i = j - 1;
        }
        else if (c == '(')
        {
            op.push(c);
        }
        else if (c == ')')
        {
            while (op.top() != '(')
            {
                eval();
            }
            op.pop();
        }
        else
        {
            while (op.size() && pr[op.top()] >= pr[c])
            {
                eval();
            }
            op.push(c);
        }
    }
    while (op.size())
    {
        eval();
    }
    cout << num.top() << endl;
    return 0;
}