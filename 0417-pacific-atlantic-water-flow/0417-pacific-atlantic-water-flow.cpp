class Solution {
public:
    bool validMove(int i , int j , int m , int n){
        return i>=0 && j>=0 && i<m && j<n;
    }
    void dfs(int i , int j , vector<vector<int>>& heights , vector<vector<bool>>& vis){
        vis[i][j] = true;
        int m = heights.size(), n = heights[0].size();
        vector<pair<int,int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(auto [di,dj] : dir){
            int ni = i + di , nj = j + dj;
            if(validMove(ni,nj,m,n) && nj<n && !vis[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(ni,nj,heights,vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false)); 
        for(int i=0;i<m;i++){
            dfs(i,0,heights,pac);
        }
        for(int j=0;j<n;j++){
            dfs(0,j,heights,pac);
        }
        
        for(int i=0;i<m;i++){
            dfs(i,n-1,heights,atl);
        }
        for(int j=0;j<n;j++){
            dfs(m-1,j,heights,atl);
        }
        vector<vector<int>> result;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};