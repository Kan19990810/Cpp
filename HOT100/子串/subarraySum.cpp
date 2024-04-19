#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> pre;
        pre[0] = 1;
        int cum = 0;
        int ans = 0;
        for (int x : nums)
        {
            cum += x;
            ans += pre[cum - k];
            pre[cum]++;
        }
        return ans;
    }
};