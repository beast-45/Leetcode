class Solution {
public:
    int solve(int index , int n , bool canBuy , vector<int> &prices , vector<vector<int>> &dp){
        if(index == n) return 0;
        if(dp[index][canBuy] != -1) return dp[index][canBuy];
        int profit = 0;
        if(canBuy){
            int buy = -prices[index] + solve(index+1,n,false,prices,dp);
            int skip = solve(index+1,n,true,prices,dp);
            profit = max(buy,skip);
        }else{
            int sell = prices[index] + solve(index+1,n,true,prices,dp);
            int hold = solve(index+1,n,false,prices,dp);
            profit = max(sell,hold);
        }
        return dp[index][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,n,true,prices,dp);
    }
};