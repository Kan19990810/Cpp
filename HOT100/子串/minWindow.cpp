#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        unordered_map<char, int> chrNum;
        unordered_set<char> speChr;

        for (auto ch : t)
        {
            chrNum[ch]--;
            speChr.insert(ch);
        }

        int target = speChr.size();
        int i = 0, j = 0;
        int index = 0, ans = n;
        for (; j < n; ++j)
        {
            if (speChr.count(s[j]))
            {
                chrNum[s[j]]++;
                if (chrNum[s[j]] == 0)
                {
                    target--;
                }

                while (target == 0)
                {
                    if (ans > j - i + 1)
                    {
                        ans = j - i + 1;
                        index = i;
                    }
                    if (speChr.count(s[i]))
                    {
                        chrNum[s[i]]--;
                        if (chrNum[s[i]] == -1)
                        {
                            target++;
                        }
                    }
                    i++;
                }
            }
        }
        return s.substr(index, ans);
    }
};