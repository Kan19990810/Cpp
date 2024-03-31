class Solution
{
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold)
    {
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); i++)
        {
            if (nums[i] > threshold)
            {
                j = i + 1;
                continue;
            }

            if (i == j)
            {
                if (nums[i] % 2 != 0)
                {
                    j = i + 1;
                    continue;
                }

                res = max(1, res);
            }
            else
            {
                if (nums[i] % 2 == nums[i - 1] % 2)
                {
                    if (nums[i] % 2 != 0)
                    {
                        j = i + 1;
                    }
                    else
                    {
                        j = i;
                    }
                    continue;
                }
                res = max(res, i - j + 1);
            }
        }
        return res;
    }
};