class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(k<1) return -1;
        vector<vector<pair<int,int>>> graph(n);
        for(auto &edge : edges){
            graph[edge[0]].push_back({edge[1],edge[2]}); // u->{v,w}
        } 
        vector<vector<int>> result(n,vector<int>(k+1,INT_MAX));
        using T = tuple<int,int,int>; //<wt,nNode,consCharCount>
        priority_queue<T,vector<T>,greater<T>> pq;
        result[0][1] = 0;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [wt,u,c] = pq.top();
            pq.pop();
            if(wt > result[u][c]) continue;
            if(u == n-1) return wt;
            for(auto [v,nWt] : graph[u]){
                int nc = (labels[u] == labels[v]) ? c+1 : 1;
                if(nc>k) continue; // more than k cons chars.
                if(wt + nWt < result[v][nc]){
                    result[v][nc] = wt + nWt;
                    pq.push({result[v][nc],v,nc});
                }
            }
        }
        return -1;
    }
};