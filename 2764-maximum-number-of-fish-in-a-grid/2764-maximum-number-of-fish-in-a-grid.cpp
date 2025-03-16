class Solution {
public:
    vector<vector<int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i , int j , int m , int n , vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>= n || grid[i][j] == 0){
            return 0;
        }
        int fishes = grid[i][j];
        grid[i][j] = 0;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            fishes += dfs(ni , nj , m , n , grid);
        }
        return fishes;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxFish = 0;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] > 0){
                    int fishes = dfs(i , j , m , n , grid);
                    maxFish = max(maxFish,fishes);
                }
            }
        }
        return maxFish;  
    }
};