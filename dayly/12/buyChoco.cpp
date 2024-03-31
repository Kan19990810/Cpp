class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int pre = 100, mi = 100;
        for (auto &price : prices)
        {
            if (price <= mi)
            {
                pre = mi;
                mi = price;
            }
            else if (price <= pre)
            {
                pre = price;
            }
            // cout << pre << ' ' << mi << endl;
        }
        int ans = money - pre - mi;
        if (ans >= 0)
        {
            return ans;
        }
        return money;
    }
};