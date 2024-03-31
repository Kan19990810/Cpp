class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        int idx_coin = 0;
        long long ma_s = 0;
        int res = 0;
        while (ma_s < target)
        {
            // 可以表达的值达到 coins[i] - 1, 则在coins[i]的基础上增加
            while (idx_coin < n && ma_s >= coins[idx_coin] - 1)
            {
                ma_s += coins[idx_coin];
                idx_coin++;
            }
            if (ma_s < target)
            {
                res++;
                ma_s = ma_s * 2 + 1;
            }
        }
        return res;
    }
};