class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i , int j , int &r2 , int &c2, int m , int n , vector<vector<int>> &land){
        if(i<0 || i>=m || j<0 || j>=n || land[i][j] == 0){
            return;
        }
        land[i][j] = 0;
        r2 = max(r2,i);
        c2 = max(c2,j);
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            dfs(ni,nj,r2,c2,m,n,land);
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> result;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(land[i][j] == 1){
                    int r2 = -1;
                    int c2 = -1;
                    dfs(i,j,r2,c2,m,n,land);
                    result.push_back({i,j,r2,c2});
                }
            }
        }
        return result; 
    }
};