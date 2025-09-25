class Solution {
public:
    int solve(int i , int j , int n , vector<vector<int>> &t , vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = t[i][j] + min(solve(i+1,j,n,t,dp),solve(i+1,j+1,n,t,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,n,triangle,dp);
    }
};