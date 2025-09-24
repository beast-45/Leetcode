class Solution {
public:
    int solve(int index , int amount , int n , vector<int> &coins , vector<vector<int>> &dp){
        if(index >= n || amount < 0){
            return 0;
        }
        if(amount == 0) return 1;
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int take = solve(index,amount-coins[index],n,coins,dp);
        int skip = solve(index+1,amount,n,coins,dp);
        return dp[index][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(0,amount,n,coins,dp);
    }
};