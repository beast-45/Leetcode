class Solution {
public:
    int t[5001][2];
    int maxP(vector<int>& prices, int day, int n, int canBuy) {
        if(day >= n) return 0;
        int profit = 0;
        if(t[day][canBuy] != -1) return t[day][canBuy];
        if(canBuy) {
            int buy = maxP(prices, day+1, n, false) - prices[day];
            int skip = maxP(prices, day+1, n, true);
            profit = max(buy,skip);
        } else {
            int sell = maxP(prices, day+2, n, true) + prices[day];
            int hold = maxP(prices, day+1, n, false);
            profit = max(sell,hold); 
        }
        return t[day][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return maxP(prices, 0, n, true);
    }
};