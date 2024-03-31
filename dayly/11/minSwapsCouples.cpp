class Solution
{
public:
    int minSwapsCouples(vector<int> &row)
    {
        unordered_map<int, int> row_idx;
        for (int i = 0; i < row.size(); i++)
        {
            row_idx[row[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < row.size() / 2; i++)
        {
            int pre = row[i * 2];
            if (pre % 2 == 0)
            {
                if (row[i * 2 + 1] == pre + 1)
                {
                    continue;
                }
                res++;
                int idx = row_idx[pre + 1];
                row[idx] = row[i * 2 + 1];
                row_idx[row[i * 2 + 1]] = idx;
            }
            else
            {
                if (row[i * 2 + 1] == pre - 1)
                {
                    continue;
                }
                res++;
                int idx = row_idx[pre - 1];
                row[idx] = row[i * 2 + 1];
                row_idx[row[i * 2 + 1]] = idx;
            }
        }
        return res;
    }
};