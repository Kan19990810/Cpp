class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet;
        for (auto num : nums)
        {
            numSet.emplace(num);
        }

        int ans = 0;
        for (auto num : numSet)
        {
            if (!numSet.count(num - 1))
            {
                int cur = num;
                int curl = 1;
                while (numSet.count(cur + 1))
                {
                    cur++;
                    curl++;
                }
                ans = max(ans, curl);
            }
        }
        return ans;
    }
};