class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int oldPrice = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > oldPrice) {
                totalProfit += prices[i] - oldPrice;
            }
            oldPrice = prices[i];
        }

        return totalProfit;
    }
};