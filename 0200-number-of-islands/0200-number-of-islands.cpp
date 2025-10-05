class Solution {
public:
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i , int j , int m , int n , vector<vector<char>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        for(auto &[di,dj] : directions){
            int ni = i + di , nj = j + dj;
            dfs(ni,nj,m,n,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size() , n = grid[0].size();
        int count = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,m,n,grid);
                    count += 1;
                }
            }
        }
        return count;
    }
};
