class Solution {
public: 
    int m,n;
    int M = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int i , int j , int rem , vector<vector<int>> &grid , int k){
        if(i>=m || j>=n){
            return 0;
        } 
        rem = (rem + grid[i][j])%k;
        if(dp[i][j][rem] != -1){
            return dp[i][j][rem];
        }
        if(i==m-1 && j==n-1){
            return rem == 0 ? 1 : 0; 
        }
        long long right = solve(i,j+1,rem,grid,k);
        long long down  = solve(i+1,j,rem,grid,k);
        return dp[i][j][rem] = (right + down) % M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return solve(0,0,0,grid,k);
    }
};