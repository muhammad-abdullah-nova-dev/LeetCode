class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int minPrice=INT_MAX;
        for(int price : prices)
        {
            minPrice=min(minPrice,price);
            int profit=price-minPrice;
            maxprofit=max(maxprofit,profit);
        }
    return maxprofit;
    }
};