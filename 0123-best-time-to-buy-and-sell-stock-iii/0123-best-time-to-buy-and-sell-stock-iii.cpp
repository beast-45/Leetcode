class Solution {
public:
    int solve(int index , bool canBuy , vector<int> &prices ,  vector<vector<vector<int>>> &dp, int transactions){
        if(index == prices.size() || transactions > 1) return 0;
        if(dp[index][canBuy][transactions] != -1) return dp[index][canBuy][transactions];
        int profit = 0;
        if(canBuy){
            int buy = -prices[index] + solve(index+1,false,prices,dp,transactions);
            int skip = solve(index+1,true,prices,dp,transactions);
            profit = max(buy,skip);
        }
        else{
            int sell = prices[index] + solve(index+1,true,prices,dp,transactions+1);
            int hold = solve(index+1,false,prices,dp,transactions);
            profit = max(sell,hold);
        }
        return dp[index][canBuy][transactions] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,true,prices,dp,0);
    }
};