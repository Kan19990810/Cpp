class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> nums_idx;
        for (int i = 0; i < n; i++)
        {
            nums_idx.push_back({nums[i], i});
        }
        sort(nums_idx.begin(), nums_idx.end());

        vector<int> ans;
        for (int i = 0, j = n - 1; i < j; i++)
        {
            while (nums_idx[i].first + nums_idx[j].first > target)
            {
                j--;
            }
            if (nums_idx[i].first + nums_idx[j].first == target)
            {
                ans = {nums_idx[i].second, nums_idx[j].second};
                break;
            }
        }
        return ans;
    }
};