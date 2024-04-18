#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zeroCount = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] != 0)
            {
                nums[i++] = nums[j];
            }
        }
        for (; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};