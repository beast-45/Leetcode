class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<bool>>> vis(m+1,vector<vector<bool>>(n+1,vector<bool>(k+1,false)));
        vector<pair<int,int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
        q.push({0,0,k});
        vis[0][0][k] = true;
        int path = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int i = q.front()[0];
                int j = q.front()[1];
                int o = q.front()[2];
                q.pop();
                if(i == m-1 && j == n-1) return path;
                for(auto &[di,dj] : directions){
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni>=0 && ni<m && nj>=0 && nj<n){
                        if(grid[ni][nj] == 1 && o > 0 && !vis[ni][nj][o-1]){
                            q.push({ni,nj,o-1});
                            vis[ni][nj][o-1] = true;
                        }
                        else if(grid[ni][nj] == 0 && !vis[ni][nj][o]){
                            q.push({ni,nj,o});
                            vis[ni][nj][o] = true;
                        }
                    }
                }
            }
            path += 1;
        }
        return -1;
    }
};