class Solution
{
public:
    vector<int> findPeaks(vector<int> &mountain)
    {
        vector<int> res;
        int pre = mountain[0];
        bool is_ri = false;
        for (int i = 1; i < mountain.size(); i++)
        {
            if (mountain[i] < pre && is_ri)
            {
                res.push_back(i - 1);
            }
            is_ri = (mountain[i] > pre);
            pre = mountain[i];
        }
        return res;
    }
};