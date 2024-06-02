#include <numeric>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long numberOfWeeks(vector<int> &milestones)
    {
        int n = milestones.size();
        if (n == 1)
        {
            return 1;
        }

        sort(milestones.begin(), milestones.end(), greater<int>());
        int week = 0;
        int pre = milestones[0];
        for (int i = 1; i < n; ++i)
        {
            int cur = milestones[i];
            int num = min(cur, pre);
            week += num;
            cout << pre << ' ' << cur << ' ' << week << '\n';
            pre -= num;
            cur -= num;
            if (cur > 0)
                pre = cur;
        }
        if (pre == 0)
            return week * 2;
        else
            return week * 2 + 1;
    }
};