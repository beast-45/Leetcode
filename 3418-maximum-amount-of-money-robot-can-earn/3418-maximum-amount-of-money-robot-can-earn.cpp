class Solution {
public:
    int solve(int i , int j , int m , int n , int neu , vector<vector<int>> &coins , vector<vector<vector<int>>> &dp){
        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && neu > 0){
                return 0;
            }
            return coins[i][j];
        }
        if(i >= m || j >= n) return INT_MIN;
        if(dp[i][j][neu] != INT_MIN){
            return dp[i][j][neu];
        }
        int take = coins[i][j] + max(solve(i+1,j,m,n,neu,coins,dp),solve(i,j+1,m,n,neu,coins,dp));
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0){
            skip = max(solve(i+1,j,m,n,neu-1,coins,dp),solve(i,j+1,m,n,neu-1,coins,dp));
        }
        return dp[i][j][neu] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size() , n = coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return solve(0,0,m,n,2,coins,dp);
    }
};