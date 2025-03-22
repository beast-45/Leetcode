class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i , int j , vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            dfs(ni,nj,grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int col=0 ; col<n ; col++){
            if(grid[0][col] == 0){
                dfs(0,col,grid);
            }
            if(grid[m-1][col] == 0){
                dfs(m-1,col,grid);
            }
        }
        for(int row=0 ; row<m ; row++){
            if(grid[row][0] == 0){
                dfs(row,0,grid);
            }
            if(grid[row][n-1] == 0){
                dfs(row,n-1,grid);
            }
        }
        int islands = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    dfs(i,j,grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};