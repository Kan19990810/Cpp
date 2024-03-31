#include <queue>
#include <vector>
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        sort(nums.begin(), nums.end());

        for (auto &n : nums)
        {
            q.push(n);
        }

        long long ans = 0;
        while (q.size() >= 2 && q.top() < k)
        {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            long long t = (long long)2 * x + y;
            ans++;
            if (t <= k)
            {
                q.push(t);
            }
        }
        if (q.size() == 1 && q.top() < k)
        {
            ans++;
        }
        return ans;
    }
};