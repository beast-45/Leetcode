class Solution {
public:
    vector<vector<int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i , int j , int m , int n , vector<vector<int>> &grid1 , vector<vector<int>>&grid2){
        if(i<0 || i>=m || j<0 || j>=n){
            return true;
        }
        if(grid2[i][j] == 0){
            return true;
        }
        grid2[i][j] = 0;
        bool result = (grid1[i][j] == 1);
        for(auto &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            result &= dfs(ni , nj , m , n , grid1 , grid2);
        }
        return result;
    }  
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int count = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid2[i][j] == 1 && dfs(i,j,m,n,grid1,grid2)){
                    count += 1;
                }
            }
        }
        return count;
    }
};