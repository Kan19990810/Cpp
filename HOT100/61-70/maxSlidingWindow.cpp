#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        auto cmp = [&](pair<int, int> a, pair<int, int> b)
        {
            return a.first < b.first;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        int s = 0;
        for (int i = 0; i < k; i++)
        {
            q.push({nums[i], i});
        }
        int n = nums.size();
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; i++)
        {
            q.push({nums[i], i});
            while (i >= q.top().second + k)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};