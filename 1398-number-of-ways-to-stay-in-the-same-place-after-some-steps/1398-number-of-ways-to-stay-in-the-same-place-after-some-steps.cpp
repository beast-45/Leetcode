class Solution {
public:  
    int M = 1e9+7;
    int solve(int index , int steps , int arrLen , vector<vector<int>> &dp){
        if(steps == 0) return index == 0;
        if(index >= arrLen || index < 0) return 0;
        if(dp[steps][index] != -1){
            return dp[steps][index];
        }
        int ways = 0;
        ways = (ways + solve(index-1,steps-1,arrLen,dp))%M;
        ways = (ways + solve(index+1,steps-1,arrLen,dp))%M;
        ways = (ways + solve(index,steps-1,arrLen,dp))%M;
        return dp[steps][index] = ways%M;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1,vector<int>(steps+1,-1));
        return solve(0,steps,arrLen,dp);
    }
};