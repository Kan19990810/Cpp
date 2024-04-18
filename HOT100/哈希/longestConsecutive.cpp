#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet;
        for (auto num : nums)
        {
            numSet.emplace(num);
        }
        int ans = 0;
        for (auto num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int cur = num;
                int curl = 1;
                while (numSet.count(num + 1))
                {
                    num++;
                    cur++;
                    curl++;
                }
                ans = max(ans, curl);
            }
        }
        return ans;
    }
};