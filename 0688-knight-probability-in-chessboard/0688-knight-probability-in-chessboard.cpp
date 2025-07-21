class Solution {
public:
    double solve(int i , int j , int n , int k , vector<pair<int,int>> &directions ,  vector<vector<vector<double>>> &dp){
        if(i<0 || i>=n || j<0 || j>=n){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        double prob = 0;
        for(auto &[di,dj] : directions){
            int ni = i + di , nj = j + dj;
            prob += solve(ni,nj,n,k-1,directions,dp)/8.0;
        }
        return dp[i][j][k] = prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        vector<pair<int,int>> directions{{-2,-1},{-1,-2},{1,-2},{2,-1},{-2,1},{-1,2},{1,2},{2,1}};
        return solve(row,column,n,k,directions,dp);
    }
};