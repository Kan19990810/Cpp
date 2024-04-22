#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool is_cover(int cnt_s[], int cnt_t[])
    {
        for (int i = 'A'; i <= 'Z'; ++i)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }

        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (cnt_s[i] < cnt_t[i])
            {
                return false;
            }
        }

        return true;
    }

public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int ansL = -1, ansR = n, left = 0;
        int cnt_s[128]{}, cnt_t[128]{};
        for (auto &c : t)
        {
            cnt_t[c]++;
        }
        for (int right = 0; right < n; right++)
        {
            cnt_s[s[right]]++;
            while (is_cover(cnt_s, cnt_t))
            {
                if (right - left < ansR - ansL)
                {
                    ansL = left;
                    ansR = right;
                }
                cnt_s[s[left++]]--;
            }
        }
        return ansL < 0 ? "" : s.substr(ansL, ansR - ansL + 1);
    }
};
