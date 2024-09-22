class Solution {
public:
    int t[5001][2];
    int maxP(vector<int>& prices, int day, int n, int buy) {
        if(day >= n) return 0;
        int profit = 0;
        if(t[day][buy] != -1) return t[day][buy];
        if(buy) {
            int take      = maxP(prices, day+1, n, false) - prices[day];
            int notTake   = maxP(prices, day+1, n, true);
            profit = max({profit, take, notTake});
        } else {
            int sell      = maxP(prices, day+2, n, true) + prices[day];
            int notSell   = maxP(prices, day+1, n, false);
            profit = max({profit, sell, notSell}); 
        }
        
        return t[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return maxP(prices, 0, n, true);
    }
};