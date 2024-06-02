#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), [&](vector<int> a, vector<int> b)
             { return a[1] < b[1]; });
        int totaltime = 0;
        int preindex = 0;
        vector<int> pretime(2001, 0);
        for (int i = 0; i < n; ++i)
        {
            int curleft = tasks[i][0];
            int curright = tasks[i][1];
            int curtime = tasks[i][2];
            int runtime = max(0, curtime - pretime[curright + 1] + pretime[curright]);
            totaltime += runtime;
            for (int k = curright + 1; k < 2001; ++k)
            {
                pretime[k] += runtime;
            }
        }
        return totaltime;
    }
};