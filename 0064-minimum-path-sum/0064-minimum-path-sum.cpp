class Solution {
public:
    int dp[201][201];
    int solve(int i , int j , int m , int n , vector<vector<int>> &grid){
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int moveRight = (j+1 < n) ? grid[i][j] + solve(i , j+1 , m , n , grid) : INT_MAX;
        int moveDown  = (i+1 < m) ? grid[i][j] + solve(i+1 , j , m , n , grid) : INT_MAX; 
        return dp[i][j] = min(moveRight , moveDown);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , m , n , grid); 
    }
};