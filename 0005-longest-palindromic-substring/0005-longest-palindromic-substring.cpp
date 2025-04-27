class Solution {
public:
    bool solve(int i , int j , string &s , vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int maxLen = 0;
        vector<vector<int>> dp(1001,vector<int>(1001,-1));
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                int len = j-i+1;
                if(solve(i,j,s,dp) && len > maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start,maxLen);
    }
};