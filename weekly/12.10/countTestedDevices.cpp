class Solution
{
public:
    int countTestedDevices(vector<int> &batteryPercentages)
    {
        int res = 0;
        int cum = 0;
        for (auto &battery : batteryPercentages)
        {
            if (battery - cum > 0)
            {
                cum++;
                res++;
            }
        }
        return cum;
    }
};