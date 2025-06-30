int maxProfit(int* prices, int n) {
    int minBuyprice = prices[0], max_profit = 0;
    for(int i = 1; i < n; i++)
    {
        minBuyprice = fmin(prices[i], minBuyprice);
        max_profit = fmax(max_profit, prices[i] - minBuyprice);
    }
    return max_profit;
} 