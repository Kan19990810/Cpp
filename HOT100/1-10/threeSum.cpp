class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;

        for (int k = 0; k < n; k++)
        {
            if (k > 0 && nums[k] == nums[k - 1])
            {
                continue;
            }
            int target = -nums[k];

            for (int i = k + 1, j = n - 1; i < j; i++)
            {
                while (i < j && nums[i] + nums[j] > target)
                {
                    j--;
                }

                if (i < j && nums[i] + nums[j] == target)
                {
                    ans.push_back({nums[k], nums[i], nums[j]});
                    // cout << k << ' ' << i << ' ' << j << endl;
                    while (i + 1 < n && nums[i] == nums[i + 1])
                    {
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};