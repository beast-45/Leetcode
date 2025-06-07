class Solution {
public:
    const int M = 1e9+7;
    int solve(int start , int n , string &s , int &k , vector<int> &dp){
        if(start >= n) return 1;
        if(dp[start] != -1){
            return dp[start];
        }
        if(s[start] == '0') return dp[start] = 0;
        int ans = 0;
        long long num = 0;
        for(int end = start ; end < s.length() ; end++){
            num = (num*10) + (s[end]-'0');
            if(num > k) break;
            ans = (ans%M + solve(end+1,n,s,k,dp)%M)%M;
        }
        return dp[start] = ans;
    }
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0,n,s,k,dp);
    }
};