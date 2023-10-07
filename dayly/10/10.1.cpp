class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minPrice = inf, maxProfit = 0;

        for (int price : prices)
        {
            maxProfit = max(maxProfit, price - minPrice);
            minPrice = min(price, minPrice);
        }
        return maxProfit;
    }
};