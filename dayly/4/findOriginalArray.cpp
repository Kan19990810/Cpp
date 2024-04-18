
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        int n = changed.size();
        unordered_map<int, int> numMap;
        vector<int> origin;
        sort(changed.begin(), changed.end());
        // 每个数字计数
        for (auto change : changed)
        {
            numMap[change]++;
        }

        if (n % 2 != 0 || numMap[0] % 2 != 0)
        {
            return {};
        }

        // 遍历每个数，查看是否有2倍
        for (auto change : changed)
        {
            if (numMap[change] > 0 && numMap[2 * change] > 0)
            {
                origin.push_back(change);
                numMap[change]--;
                numMap[2 * change]--;
                n -= 2;
            }
        }
        if (n == 0)
        {
            return origin;
        }
        return {};
    }
};