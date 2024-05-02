class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int step = 0;
        int dis = 0;
        int idx = 0;

        if (nums.size() == 0)
        {
            return 0;
        }

        while (dis < nums.size() - 1)
        {
            int thisdis = 0;
            int thisidx = 0;
            for (int i = idx; i <= dis; ++i)
            {
                if (i + nums[i] > thisdis)
                {
                    thisdis = i + nums[i];
                    thisidx = i;
                }
            }
            step++;
            dis = thisdis;
            idx = thisidx;
        }
        return step;
    }
};