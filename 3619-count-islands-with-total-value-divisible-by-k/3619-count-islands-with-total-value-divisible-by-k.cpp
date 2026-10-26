class Solution {
public:
    using ll = long long;
    vector<pair<int,int>> directions{{0,-1},{0,1},{-1,0},{1,0}};
    ll dfs(int i , int j , int m , int n , vector<vector<int>> &grid , vector<vector<bool>> &vis){
        ll val = grid[i][j];
        vis[i][j] = true;
        for(auto &[di,dj] : directions){
            int ni = i + di , nj = j + dj;
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] > 0 && !vis[ni][nj]){
                val += dfs(ni,nj,m,n,grid,vis);
            }
        }
        return val;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size() , count = 0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] != 0  && !vis[i][j]){
                    ll val = dfs(i,j,m,n,grid,vis);
                    if(val%k == 0) count += 1;
                }
            }
        }
        return count;
    }
};