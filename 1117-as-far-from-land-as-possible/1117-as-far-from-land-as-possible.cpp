class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
        queue<pair<int,int>> q;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        int farthest = 0;
        while(!q.empty()){
            int s = q.size();
            bool hit = false;
            while(s--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto &direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==0){
                        grid[ni][nj] = 1;
                        hit = true;
                        q.push({ni,nj});
                    }
                }
            }
            if(hit){
                farthest++;
            }
        }
        return farthest == 0 ? -1 : farthest;
    }
};