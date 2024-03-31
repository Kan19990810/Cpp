class Solution
{
public:
    int maximizeSum(vector<int> &nums, int k)
    {
        auto maxposition = max_element(nums.begin(), nums.end());
        return (*maxposition) * k + (k - 1) * k / 2;
    }
};