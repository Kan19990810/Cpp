#include <algorithm>
class Solution
{
public:
    int minIncrements(int n, vector<int> &cost)
    {
        int ans = 0;
        for (int i = n / 2; i > 0; i--)
        {
            ans += abs(cost[i * 2 - 1] - cost[i * 2]);
            cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]);
        }
        return ans;
    }
};