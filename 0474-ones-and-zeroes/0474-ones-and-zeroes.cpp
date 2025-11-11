class Solution {
public:
    int solve(int index , int m , int n , vector<pair<int,int>> &counts , vector<vector<vector<int>>> &dp){
        if(index >= counts.size() || (m == 0 && n == 0)) return 0;
        if (dp[index][m][n] != -1){
            return dp[index][m][n];
        }
        int take = 0;
        if(counts[index].first <= m && counts[index].second <= n){
            take = 1 + solve(index+1,m-counts[index].first,n-counts[index].second,counts,dp);
        }
        int skip = solve(index+1,m,n,counts,dp);
        return dp[index][m][n] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> counts;
        for(string &s : strs){
            int ones = 0 , zeroes = 0;
            for(int i=0 ; i<s.length() ; i++){
                s[i] == '0' ? zeroes++ : ones++;
            }
            counts.push_back({zeroes,ones});
        }
        vector<vector<vector<int>>> dp(counts.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,counts,dp);
    }
};