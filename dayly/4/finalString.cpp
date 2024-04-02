#include <string>
#include <deque>

using namespace std;
class Solution
{
public:
    string finalString(string s)
    {
        /**
         * 2810. 故障键盘

你的笔记本键盘存在故障，每当你在上面输入字符 'i' 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。

给你一个下标从 0 开始的字符串 s ，请你用故障键盘依次输入每个字符。

返回最终笔记本屏幕上输出的字符串。

        */

        int n = s.size();
        string ans;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'i')
            {
                reverse(ans.begin(), ans.end());
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};