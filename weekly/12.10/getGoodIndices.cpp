class Solution
{
public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> res;
        int n = variables.size();
        for (int i = 0; i < n; i++)
        {
            int a = variables[i][0], b = variables[i][1], c = variables[i][2], m = variables[i][3];
            int cur_1 = 1, cur_2 = 1;
            while (b--)
            {
                cur_1 *= a;
                cur_1 %= 10;
            }
            while (c--)
            {
                cur_2 *= cur_1;
                cur_2 %= m;
            }
            if (cur_2 == target)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};