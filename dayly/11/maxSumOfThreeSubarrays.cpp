class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> ans;
        int sum1 = 0, maxsum1 = 0, maxsum1idx = 0;
        int sum2 = 0, maxsum12 = 0, maxsum12idx1 = 0, maxsum12idx2 = 0;
        int sum3 = 0, maxtotal = 0;
        for (int i = k * 2; i < nums.size(); i++)
        {
            sum1 += nums[i - k * 2];
            sum2 += nums[i - k];
            sum3 += nums[i];
            if (i >= k * 3 - 1)
            {
                if (sum1 > maxsum1)
                {
                    maxsum1 = sum1;
                    maxsum1idx = i - k * 3 + 1;
                }
                if (maxsum1 + sum2 > maxsum12)
                {
                    maxsum12 = maxsum1 + sum2;
                    maxsum12idx1 = maxsum1idx;
                    maxsum12idx2 = i - 2 * k + 1;
                }
                if (maxsum12 + sum3 > maxtotal)
                {
                    maxtotal = maxsum12 + sum3;
                    ans = {maxsum12idx1, maxsum12idx2, i - k + 1};
                }
                sum1 -= nums[i - k * 3 + 1];
                sum2 -= nums[i - k * 2 + 1];
                sum3 -= nums[i - k + 1];
            }
        }
        return ans;
    }
};