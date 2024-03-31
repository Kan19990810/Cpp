class Solution
{
public:
    long long maximumStrength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> preSum(n + 1);

        // 计算前缀和
        for (int i = 0; i < n; i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int stIdx = 0;
        // 遍历第k个子数组
        for (int t = 1; t <= k; t++)
        {
            // 可选的区间[stIdx, endIdx]
            int endIdx = n - t;
            int choiceIdx = -1;
            long long preNum = 0;
            for (int i = stIdx; i <= endIdx; i++)
            {
                // 没有
                if (choiceIdx == -1)
                {
                    choiceIdx = i;
                    preNum = preSum[i];
                    continue;
                }
                if (t % 2 == 1 && preSum[i] > preNum)
                {
                    choiceIdx = i;
                    preNum = preSum[i];
                }
                if (t % 2 == 0 && preSum[i] < preNum)
                {
                    choiceIdx = i;
                    preNum = preSum[i];
                }
            }
        }
    }
};