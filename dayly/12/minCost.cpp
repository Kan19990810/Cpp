#include <numeric>
class Solution
{
public:
    long long minCost(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> min_num(nums);
        long long ans = accumulate(min_num.begin(), min_num.end(), 0LL);
        for (int k = 1; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                min_num[i] = min(min_num[i], nums[(i + k) % n]);
            }
            ans = min(ans, static_cast<long long>(k) * x + accumulate(min_num.begin(), min_num.end(), 0LL));
        }
        return ans;
    }
};