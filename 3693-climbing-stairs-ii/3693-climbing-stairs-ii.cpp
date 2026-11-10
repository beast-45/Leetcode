class Solution {
public:
    int solve(int i , int n , vector<int> &costs, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;
        for(int step=1 ; step<=3 ; step++){
            int j = i + step;
            if(j <= n){
                int c = costs[j-1] + ((j-i)*(j-i)) + solve(j,n,costs,dp);
                minCost = min(minCost,c);
            }
        }
        return dp[i] = minCost;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,-1);
        return solve(0,n,costs,dp);
    }
};