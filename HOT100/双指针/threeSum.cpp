#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int k = 0; k < n - 2; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            int one = nums[k];
            for (int i = k + 1, j = n - 1; i < j; i++)
            {

                int two = nums[i];
                while (i < j && one + two + nums[j] > 0)
                {
                    // cout << one + two + nums[j] << endl;
                    j--;
                }
                if (i < j && one + two + nums[j] == 0)
                {
                    ans.push_back({one, two, nums[j]});
                    while (i < n - 1 && nums[i] == nums[i + 1])
                    {
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};