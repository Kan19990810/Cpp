
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string baseNeg2(int n)
    {
        vector<int> mid;
        while (n)
        {
            mid.push_back(n % 2);
            n /= 2;
        }
        int tmp = 0;
        vector<int> ans;
        for (int i = 0; i < mid.size(); ++i)
        {
            if (i % 2)
            {
                int x = tmp + mid[i];
                if (x == 0)
                {
                    ans.push_back(0);
                    tmp = 0;
                }
                else if (x == 1)
                {
                    ans.push_back(1);
                    tmp = 1;
                }
                else
                {
                    ans.push_back(0);
                    tmp = 1;
                }
            }
            else
            {
                int x = tmp + mid[i];
                if (x <= 1)
                {
                    ans.push_back(x);
                    tmp = 0;
                }
                else
                {
                    ans.push_back(0);
                    tmp = 1;
                }
            }
        }

        if (tmp)
        {
            if (mid.size() % 2)
            {
                ans.push_back(1);
                ans.push_back(1);
            }
            else
            {
                ans.push_back(1);
            }
        }

        string s;
        for (int i = ans.size() - 1; i >= 0; --i)
        {
            s += to_string(ans[i]);
        }
        if (s.size() == 0)
        {
            s += '0';
        }
        return s;
    }
};