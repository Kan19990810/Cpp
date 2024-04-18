#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j; j--)
        {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            while (height[i] < height[j])
            {
                i++;
                ans = max(ans, min(height[i], height[j]) * (j - i));
            }
        }
        return ans;
    }
};