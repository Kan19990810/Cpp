class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<int> pre = {1};
        vector<vector<int>> ans;
        ans.push_back(pre);
        numRows--;
        while (numRows--)
        {
            vector<int> cur;
            for (int i = 0; i < pre.size(); ++i)
            {
                if (i == 0)
                {
                    cur.push_back(pre[0]);
                }
                else
                    cur.push_back(pre[i - 1] + pre[i]);
            }
            cur.push_back(1);
            pre = cur;
            ans.push_back(cur);
        }
        return ans;
    }
};