class Solution {
public:
    int solve(int i , int j , int m , int n , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(i >= m && j >= n) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i >= m){
            return dp[i][j] = s2[j] + solve(i,j+1,m,n,s1,s2,dp);
        }else if(j >= n){
            return dp[i][j] = s1[i] + solve(i+1,j,m,n,s1,s2,dp);
        }
        if(s1[i] == s2[j]) return dp[i][j] = solve(i+1,j+1,m,n,s1,s2,dp);
        return dp[i][j] = min(s1[i] + solve(i+1,j,m,n,s1,s2,dp),s2[j] + solve(i,j+1,m,n,s1,s2,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length() , n = s2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,s1,s2,dp);
    }
};