#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= n; i++)
        {
            if (i - 2 >= 0 && nums[i - 1] == nums[i - 2])
            {
                dp[i] = dp[i] || dp[i - 2];
            }
            if (i - 3 >= 0 && nums[i - 1] == nums[i - 2] && nums[i - 2] == nums[i - 3])
            {
                dp[i] = dp[i] || dp[i - 3];
            }
            if (i - 3 >= 0 && nums[i - 1] == nums[i - 2] + 1 && nums[i - 2] == nums[i - 3] + 1)
            {
                dp[i] = dp[i] || dp[i - 3];
            }
        }

        return dp[n];
    }
};