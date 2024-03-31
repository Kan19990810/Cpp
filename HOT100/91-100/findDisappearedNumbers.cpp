class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> st(n);
        for (auto num : nums)
        {
            st[num] = true;
        }

        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == false)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};