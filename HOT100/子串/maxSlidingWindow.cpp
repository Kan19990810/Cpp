#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();

        vector<int> res;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; ++i)
        {
            pq.push({nums[i], i});
            if (i < k - 1)
            {
                continue;
            }
            while (pq.top().second <= i - k)
            {
                pq.pop();
            }
            // cout << pq.top().first << endl;
            res.push_back(pq.top().first);
        }
        return res;
    }
};