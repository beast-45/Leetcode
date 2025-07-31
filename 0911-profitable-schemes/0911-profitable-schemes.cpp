class Solution {
public:
    int M = 1e9+7;
    int solve(int index , int members , int currProfit , int n , int minProfit , vector<int> &group , vector<int> &profit , vector<vector<vector<int>>> &dp){
        if(members > n) return 0;
        if(index >= group.size()){
            return dp[index][members][currProfit] = currProfit >= minProfit;
        }
        if(dp[index][members][currProfit] != -1){
            return dp[index][members][currProfit];
        }
        long long commit = solve(index+1,members+group[index],min(currProfit+profit[index],minProfit),n,minProfit,group,profit,dp) % M;
        long long skip = solve(index+1,members,currProfit,n,minProfit,group,profit,dp) % M;
        return dp[index][members][currProfit] = (commit + skip) % M;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(0,0,0,n,minProfit,group,profit,dp);
    }
};