class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyP = prices[0];
        int profit = 0;
        for(int i=1 ; i<n ; i++){
            if(prices[i] < buyP){
                buyP = prices[i];
            }
            profit = max(profit,prices[i]-buyP);
        }
        return profit;
    }
};