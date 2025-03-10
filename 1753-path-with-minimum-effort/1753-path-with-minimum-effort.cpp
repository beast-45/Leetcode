class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            int d = u.first;
            int x = u.second.first;
            int y = u.second.second;
            for(auto &direction : directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n){
                    int cost = max(d , abs(heights[nx][ny] - heights[x][y]));
                    if(cost < result[nx][ny]){
                        result[nx][ny] = cost;
                        pq.push({cost,{nx,ny}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};