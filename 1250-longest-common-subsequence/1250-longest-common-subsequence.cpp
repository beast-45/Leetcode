class Solution {
public:
    int solve(int index1 , int index2 , int m , int n , string &t1 , string &t2 , vector<vector<int>> &dp){
        if(index1 >= m || index2 >= n) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        if(t1[index1] == t2[index2]){
            return dp[index1][index2] = 1 + solve(index1+1,index2+1,m,n,t1,t2,dp);
        }
        return dp[index1][index2] = max(solve(index1+1,index2,m,n,t1,t2,dp),solve(index1,index2+1,m,n,t1,t2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size() , n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return  solve(0,0,m,n,text1,text2,dp);
    }
};