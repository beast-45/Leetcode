class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }
        int path = 0;
        q.push({0,0});
        grid[0][0] = -1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == m-1 && y == n-1){
                    return path + 1;
                }
                for(vector<int> &direction : directions){
                    int nx = x + direction[0];
                    int ny = y + direction[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                        q.push({nx,ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            path+=1;
        }
        return -1;
    }
};