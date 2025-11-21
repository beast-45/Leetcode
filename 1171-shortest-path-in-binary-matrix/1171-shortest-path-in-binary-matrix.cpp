class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }
        vector<pair<int,int>> directions{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        int path = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto [i,j] = q.front();
                q.pop();
                if(i == m-1 && j == n-1) return path+1;
                for(auto &[di,dj] : directions){
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 0){
                        q.push({ni,nj});
                        grid[ni][nj] = 1;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};