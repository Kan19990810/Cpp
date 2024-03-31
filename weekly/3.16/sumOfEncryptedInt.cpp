class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int ans = 0;
        for (auto num : nums)
        {
            int l = 0;
            int ma = 0;
            while (num)
            {
                ma = max(ma, num % 10);
                l++;
                num /= 10;
            }
            int res = 0;
            for (int i = 1; i <= l; i++)
            {
                res = res * 10 + ma;
            }
            ans += res;
        }
        return ans;
    }
};