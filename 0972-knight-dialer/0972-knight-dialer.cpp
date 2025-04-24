class Solution {
public:
    int M = 1e9+7;
    int solve(int remaining , int start , vector<vector<int>> &adj , vector<vector<int>> &dp){
        if(remaining == 0){
            return 1;
        }
        if(dp[remaining][start] != -1){
            return dp[remaining][start];
        }
        int res = 0;
        for(int &nextMove : adj[start]){
            res = (res + solve(remaining-1,nextMove,adj,dp)) % M;
        }
        return dp[remaining][start] = res;
    }
    int knightDialer(int n) {
        vector<vector<int>> adj{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp(n+1,vector<int>(10,-1));
        int numbers = 0;
        for(int start=0 ; start<=9 ; start++){
            numbers = (numbers + solve(n-1,start,adj,dp)) % M;
        }
        return numbers;
    }
};