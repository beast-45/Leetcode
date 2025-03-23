class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    bool dfs(int i , int j , int parentI , int parentJ , char ch , vector<vector<char>> &grid , vector<vector<bool>> &vis){
        vis[i][j] = true;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==ch){
                if(!vis[ni][nj]){
                    if(dfs(ni,nj,i,j,ch,grid,vis)){
                        return true;
                    }
                }
                else if(ni != parentI || nj != parentJ){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(!vis[i][j]){
                    char ch = grid[i][j];
                    if(dfs(i,j,-1,-1,ch,grid,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};