class Solution {
public:
    int solve(int idx1 , int idx2 , int n , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(idx1 >= n || idx2 >= n) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]){
            return 1 + solve(idx1+1,idx2+1,n,s1,s2,dp);
        }
        return dp[idx1][idx2] = max(solve(idx1+1,idx2,n,s1,s2,dp),solve(idx1,idx2+1,n,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s1 = s;
        reverse(begin(s1),end(s1));
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,n,s,s1,dp);
    }
};