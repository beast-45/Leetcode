class Solution {
public:
    int solve(int index , string &s , int n , vector<int> &dp){
        if(index == n){
            return 1;
        }
        if( s[index] == '0'){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int result = solve(index+1 , s , n , dp);
        if(index + 1 < n && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))){
            result += solve(index+2 , s , n , dp);
        }
        return dp[index] = result;
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1,-1);
        return solve(0 , s , n , dp);
    }
};