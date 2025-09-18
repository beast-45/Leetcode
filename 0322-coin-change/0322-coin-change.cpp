class Solution {
public:
    int solve(int index , int n , int amount , vector<int> &nums , vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(amount < 0 || index >= n) return 1e6;
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int take = 1 + solve(index,n,amount-nums[index],nums,dp);
        int skip = solve(index+1,n,amount,nums,dp);
        return dp[index][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int minCoins = solve(0,n,amount,coins,dp);
        return minCoins == 1e6 ? -1 : minCoins;
    }
};