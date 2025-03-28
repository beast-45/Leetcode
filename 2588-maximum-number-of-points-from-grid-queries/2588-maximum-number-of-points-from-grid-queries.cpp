class Solution {
public:
    typedef vector<int> V;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        int k = queries.size();

        vector<pair<int,int>> sortedQueries;
        for(int i=0 ; i<k ; i++){
            sortedQueries.push_back({queries[i],i});
        }

        sort(begin(sortedQueries),end(sortedQueries));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        priority_queue<V,vector<V>,greater<V>> pq;
        vector<int> answer(k);
        int score = 0;

        pq.push({grid[0][0],0,0});
        vis[0][0] = true;

        for(int i=0 ; i<k ; i++){
            int queryVal = sortedQueries[i].first;
            int index = sortedQueries[i].second;
            while(!pq.empty() && pq.top()[0] < queryVal){
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                score += 1;
                for(auto &direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(ni>=0 && ni<m && nj>=0 && nj<n &&  !vis[ni][nj]){
                        pq.push({grid[ni][nj],ni,nj});
                        vis[ni][nj] = true;
                    }
                }
            }
            answer[index] = score;
        }
        return answer;
    }
};