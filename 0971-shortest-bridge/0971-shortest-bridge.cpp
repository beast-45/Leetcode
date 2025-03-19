class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i , int j , int m , int n , vector<vector<int>> &grid , queue<pair<int,int>> &q){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == 0){
            return;
        }
        q.push({i,j});
        grid[i][j] = 0;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            dfs(ni,nj,m,n,grid,q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        bool found = false;
        for(int i=0 ; i<m && !found ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    dfs(i,j,m,n,grid,q);
                    found = true;
                    break;
                }
            }
        }
        int shortestBridge = 0;
        int bridge = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(vector<int> &direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n){
                        if(grid[ni][nj] == 1){
                            return bridge;
                        }
                        else if(grid[ni][nj] == 0){
                            q.push({ni,nj});
                            grid[ni][nj] = -1;
                        }
                    }
                }
            }
            bridge++;
        }
        return -1;
    }
};