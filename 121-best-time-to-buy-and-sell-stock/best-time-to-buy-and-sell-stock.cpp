class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buyprice = prices[0], max_profit = 0;
        for(int i = 1; i < prices.size();i++){
            min_buyprice = min(min_buyprice, prices[i]);
            max_profit = max(max_profit, prices[i] - min_buyprice);
        }
        return max_profit;
    }
};