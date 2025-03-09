class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        vector<vector<int>> result(m , vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({1,{0,0}});
        result[0][0] = 1;
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            int d = u.first;
            int x = u.second.first;
            int y = u.second.second;
            for(auto &dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];
                int dist = 1;
                if((nx >= 0 && nx < m && ny >= 0 && ny < n) && grid[nx][ny] == 0 && d+dist < result[nx][ny]){
                    result[nx][ny] = d+dist;
                    pq.push({result[nx][ny],{nx,ny}});

                }
            }
        }
        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }
        return result[m-1][n-1]; 
    }
};