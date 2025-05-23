class Solution {
public:
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , int m , int n , vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return 0;
        }
        int area = 1;
        grid[i][j] = 0;
        for(auto &[di,dj] : directions){
            int ni = i + di;
            int nj = j + dj;
            area += dfs(ni,nj,m,n,grid);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size() , maxArea = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,m,n,grid);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};