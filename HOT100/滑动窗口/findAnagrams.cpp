#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        int chNum[26];
        for (auto ch : p)
        {
            chNum[ch - 'a']--;
        }

        int target = 0;
        for (int i = 0; i < 26; i++)
        {
            if (chNum[i] != 0)
            {
                target++;
            }
        }

        int cur = 0;
        vector<int> res;
        for (int i = 1; i <= n; i++)
        {
            if (i <= m)
            {
                chNum[s[i - 1] - 'a']++;
                if (chNum[s[i - 1] - 'a'] == 0)
                {
                    cur++;
                }
            }
            else
            {
                if (chNum[s[i - m - 1] - 'a'] == 0)
                {
                    cur--;
                }
                chNum[s[i - m - 1] - 'a']--;

                chNum[s[i - 1] - 'a']++;
                if (chNum[s[i - 1] - 'a'] == 0)
                {
                    cur++;
                }
            }
            if (cur == target)
            {
                res.push_back(i - m);
            }
        }
        return res;
    }
};