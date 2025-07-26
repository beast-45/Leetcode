class Solution {
public:
    int solve(int i , int j , string &s , vector<vector<int>> &dp){
        if(i > j) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }
        return dp[i][j] = min(1+solve(i+1,j,s,dp),1+solve(i,j-1,s,dp));
    }
    int minInsertions(string s) {
        int n = s.length();
        int i = 0 , j = n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(i,j,s,dp);
    }
};