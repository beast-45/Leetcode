class Solution {
public:
    int solve(int index , int i , int n , vector<vector<int>> &t , vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        if(dp[index][i] != -1){
            return dp[index][i];
        }
        return dp[index][i] = t[index][i] + min(solve(index+1,i,n,t,dp),solve(index+1,i+1,n,t,dp)); 
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,n,triangle,dp);
    }
};