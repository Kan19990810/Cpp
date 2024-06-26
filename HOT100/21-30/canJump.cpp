class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxDistance = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxDistance < i)
            {
                return false;
            }
            maxDistance = max(maxDistance, i + nums[i]);
        }
        return true;
    }
};