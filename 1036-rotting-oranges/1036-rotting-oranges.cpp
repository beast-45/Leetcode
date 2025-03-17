class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        int fresh = 0;
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        while(!q.empty()){
            int s = q.size();
            bool hit = false;
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(vector<int> &direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == 1){
                        q.push({ni,nj});
                        grid[ni][nj] = 2;
                        hit = true;
                        fresh--;
                    }
                }
            }
            if(hit){
                time += 1;
            }
        }
        return fresh != 0 ? -1 : time;
        
    }
};