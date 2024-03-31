class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        int ans = 0;
        int n = coins.size();
        int up = 0;
        for (int i = 0; i < n; i++)
        {
            while (up < coins[i] - 1)
            {
                ans++;
                up = 2 * up + 1;
                if (up >= target)
                {
                    return ans;
                }
            }
            up += coins[i];
            if (up >= target)
            {
                return ans;
            }
        }
        while (up < target)
        {
            ans++;
            up = 2 * up + 1;
        }
        return ans;
    }
};