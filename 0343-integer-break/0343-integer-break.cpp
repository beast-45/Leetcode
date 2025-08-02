class Solution {
public:
    int solve(int n , vector<int> &dp){
        if(n == 1) return 1;
        if(dp[n] != -1){
            return dp[n];
        }
        int maxProduct = 1 * (n-1);
        for(int i=1 ; i<n ; i++){
            int product = i * max(n-i,solve(n-i,dp));
            maxProduct = max(maxProduct,product);
        }
        return dp[n] = maxProduct;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};