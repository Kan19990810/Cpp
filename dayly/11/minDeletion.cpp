class Solution
{
public:
    int minDeletion(vector<int> &nums)
    {
        int i = 0, res = 0, pre = -1;
        for (auto num : nums)
        {

            if (i % 2 == 1 && num == pre)
            {
                res++;
            }
            else
            {
                pre = num;
                i++;
            }
        }
        if (i % 2 == 1)
        {
            res++;
        }
        return res;
    }
};