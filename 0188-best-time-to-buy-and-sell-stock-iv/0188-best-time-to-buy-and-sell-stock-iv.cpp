class Solution {
public:
    int solve(int index , bool canBuy , vector<int> &prices ,  vector<vector<vector<int>>> &dp, int transactions , int k){
        if(index == prices.size() || transactions == k) return 0;
        if(dp[index][canBuy][transactions] != -1) return dp[index][canBuy][transactions];
        int profit = 0;
        if(canBuy){
            int buy = -prices[index] + solve(index+1,false,prices,dp,transactions,k);
            int skip = solve(index+1,true,prices,dp,transactions,k);
            profit = max(buy,skip);
        }
        else{
            int sell = prices[index] + solve(index+1,true,prices,dp,transactions+1,k);
            int hold = solve(index+1,false,prices,dp,transactions,k);
            profit = max(sell,hold);
        }
        return dp[index][canBuy][transactions] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,true,prices,dp,0,k);
    }
};