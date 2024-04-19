#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_map<char, int> chrMap;
        int ans = 0;
        int i = 0, j = 0;
        for (; j < n; j++)
        {
            // 重复字符，推进慢指针
            if (chrMap[s[j]])
            {
                while (chrMap[s[j]])
                {
                    chrMap[s[i]]--;
                    i++;
                }
            }
            // 没有重复字符，更新答案
            else
            {
                ans = max(ans, j - i + 1);
            }

            chrMap[s[j]]++;
        }
        return ans;
    }
};