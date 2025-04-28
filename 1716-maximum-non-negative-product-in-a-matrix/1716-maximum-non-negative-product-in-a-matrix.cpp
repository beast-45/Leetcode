class Solution {
public:
    #define LMX LLONG_MAX
    #define LMN LLONG_MIN
    using LL = long long;
    typedef pair<LL,LL> P;
    int m,n;
    int M = 1e9+7;
    pair<LL,LL> solve(int i , int j , vector<vector<int>> &grid,vector<vector<P>> &dp){
        if(i==m-1 && j==n-1){
            return {grid[i][j],grid[i][j]};
        }
        if(dp[i][j] != make_pair(LMN,LMX)){
            return dp[i][j];
        }
        LL maxVal = LMN;
        LL minVal = LMX;
        if(i+1 < m){
            auto [downMax,downMin] = solve(i+1,j,grid,dp);
            maxVal = max({maxVal,grid[i][j]*downMax,grid[i][j]*downMin});
            minVal = min({minVal,grid[i][j]*downMax,grid[i][j]*downMin});
        }
        if(j+1 < n){
            auto [rightMax,rightMin] = solve(i,j+1,grid,dp);
            maxVal = max({maxVal,grid[i][j]*rightMax,grid[i][j]*rightMin});
            minVal = min({minVal,grid[i][j]*rightMax,grid[i][j]*rightMin});
        }
        return dp[i][j] = {maxVal,minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size() , n = grid[0].size();
        if(grid[0][0] == 0 || grid[m-1][n-1] == 0) return 0;
        vector<vector<P>> dp(m,vector<P>(n,{LMN,LMX}));
        auto [maxProduct,minProduct] = solve(0,0,grid,dp);
        return maxProduct < 0 ? -1 : maxProduct % M;
    }
};