class Solution {
public:
    void dfs(int i , int j , int m , int n , vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return;
        }
        grid[i][j] = 0;
        dfs(i+1 , j , m , n , grid);
        dfs(i-1 , j , m , n , grid);
        dfs(i , j+1 , m , n , grid);
        dfs(i , j-1 , m , n , grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int row=0 ; row<m ; row++){
            if(grid[row][0] == 1){
                dfs(row , 0 , m , n , grid);
            }
            if(grid[row][n-1] == 1){
                dfs(row , n-1 , m , n , grid);
            }
        }
        for(int col=0 ; col<n ; col++){
            if(grid[0][col] == 1){
                dfs(0 , col , m , n , grid);
            }
            if(grid[m-1][col] == 1){
                dfs(m-1 , col , m , n , grid);
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]){
                    count += 1;
                }
            }
        }
        return count;
    }
};