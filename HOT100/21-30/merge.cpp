class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int st = -1, ed = -1;
        for (int i = 0; i < n; i++)
        {
            if (st == -1)
            {
                st = intervals[i][0];
                ed = intervals[i][1];
                continue;
            }
            if (ed >= intervals[i][0])
            {
                ed = max(ed, intervals[i][1]);
            }
            else
            {
                ans.push_back({st, ed});
                st = intervals[i][0];
                ed = intervals[i][1];
            }
        }
        ans.push_back({st, ed});
        return ans;
    }
};