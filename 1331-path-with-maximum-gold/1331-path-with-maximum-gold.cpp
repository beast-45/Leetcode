class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return 0;
        }
        int gold = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            maxGold = max(maxGold,dfs(ni,nj,grid));
        }
        grid[i][j] = gold;
        return gold+maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxGold = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] != 0){
                    int gold = dfs(i,j,grid);
                    maxGold = max(maxGold,gold);
                }
            }
        }
        return maxGold;
        
    }
};