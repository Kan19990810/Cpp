class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> freq;

        for (int num : nums)
        {
            ++freq[num];
        }

        for (const auto &[num, fre] : freq)
        {
            if (fre == 1)
            {
                ans.push_back(num);
            }
        }

        return ans;
    }
};