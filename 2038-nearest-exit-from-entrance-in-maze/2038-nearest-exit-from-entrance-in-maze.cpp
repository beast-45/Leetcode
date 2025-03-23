class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int entranceRow = entrance[0];
        int entranceCol = entrance[1];
        vis[entranceRow][entranceCol] = true;
        q.push({entranceRow,entranceCol});
        int level = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(vector<int>&direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && maze[ni][nj] == '.' && !vis[ni][nj]){
                        if(ni == m-1 || ni == 0 || nj==0 || nj==n-1){
                            return level+1;
                        }
                        q.push({ni,nj});
                        vis[ni][nj] = true;

                    }
                }
            }
            level++;
        }
        return -1;
    }
};