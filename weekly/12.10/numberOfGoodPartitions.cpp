class Solution
{
public:
    int numberOfGoodPartitions(vector<int> &nums)
    {
        static const int N = 1e9 + 7;
        // 记录每个数字的位置
        unordered_map<int, pair<int, int>> num_loc;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (num_loc.count(nums[i]) == 0)
            {
                num_loc.emplace(nums[i], pair<int, int>(i, -1));
            }
            else
            {
                num_loc[nums[i]].second = i;
            }
        }

        // 记录每个数字位置的最大和最小；
        vector<pair<int, int>> num_range;
        for (auto kv : num_loc)
        {
            auto loc = kv.second;
            cout << kv.first << ' ' << loc[0] << ' ' << loc[1];
            num_range.push_back({loc[0], loc[1]});
        }
        return 9;
    }
};