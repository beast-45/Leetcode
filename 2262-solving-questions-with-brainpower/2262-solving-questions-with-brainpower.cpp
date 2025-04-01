class Solution {
public:
    long long solveQuestions(int index , int n , vector<vector<int>> &questions , vector<long long> &dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        long long solve = questions[index][0] + solveQuestions(index+1+questions[index][1],n,questions,dp);
        long long skip  = solveQuestions(index+1,n,questions,dp);
        return dp[index] = max(solve,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return solveQuestions(0,n,questions,dp);
    }
};