class Solution {
public:
    int M = 1e9+7;
    int solve(int i , int j , int m , int n , int prev , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j][prev] != -1) return dp[i][j][prev];
        // 0 -> left , 1 -> up
        if(grid[i][j] == 1){
            if(prev == 0){
                return dp[i][j][prev] = solve(i+1,j,m,n,1,grid,dp);
            }else{
                return dp[i][j][prev] = solve(i,j+1,m,n,0,grid,dp);
            }
        }
        int totalPaths = 0;
        totalPaths = (totalPaths + solve(i,j+1,m,n,0,grid,dp))%M;
        totalPaths = (totalPaths + solve(i+1,j,m,n,1,grid,dp))%M;
        return dp[i][j][prev] = totalPaths;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(2, -1)));
        return solve(0,0,m,n,0,grid,dp);
    }
};