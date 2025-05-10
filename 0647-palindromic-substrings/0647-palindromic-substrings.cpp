class Solution {
public:
    bool checkPalindrome(int i , int j , string &s ,  vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] =  checkPalindrome(i+1,j-1,s,dp);
        return dp[i][j] = 0;  
    }
    int countSubstrings(string s) {
        int n = s.length() , count = 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                if(checkPalindrome(i,j,s,dp)){
                    count += 1;
                }
            }
        }
        return count;
    }
};