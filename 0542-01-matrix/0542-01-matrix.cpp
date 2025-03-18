class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> result(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(mat[i][j] == 0){
                    result[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto &direction  : directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n && result[nx][ny] == -1){
                    result[nx][ny] = result[x][y] + 1;
                    q.push({nx,ny});
                }
            }

        }
        return result;
    }
};