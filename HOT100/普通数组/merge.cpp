class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int ansLeft = -1;
        int ansRight = -1;
        for (auto interval : intervals)
        {
            int left = interval[0];
            int right = interval[1];
            if (left > ansRight)
            {
                if (ansLeft != -1)
                {
                    ans.push_back({ansLeft, ansRight});
                }
                ansLeft = left;
                ansRight = right;
            }
            else
            {
                ansRight = max(ansRight, right);
            }
        }
        if (ansLeft != -1)
        {
            ans.push_back({ansLeft, ansRight});
        }

        return ans;
    }
};