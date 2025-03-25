class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , vector<vector<int>> &grid , vector<vector<bool>> &vis , int &emptyCells , int count){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2){
            return count == emptyCells ? 1 : 0;
        }
        int paths = 0;
        vis[i][j] = true;
        for(auto &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            paths += dfs(ni,nj,grid,vis,emptyCells,count+1);
        }
        vis[i][j] = false;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int ways = 0;
        int x,y;
        int emptyCells = 1;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                }
                else if(grid[i][j] == 0){
                    emptyCells++;
                }
            }
        }
        return dfs(x,y,grid,vis,emptyCells,0);
    }
};