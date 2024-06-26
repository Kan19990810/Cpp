#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] <= 0)
            {
                nums[i] = n + 1;
            }
            if (nums[i] >= n + 1)
            {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            if (num <= n)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> a = {2, 1};
//     cout << s.firstMissingPositive(a);
//     return 0;
// }