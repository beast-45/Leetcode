class Solution {
public:
    typedef pair<int,int> P; 
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0 ; i<n-1 ; i++){
            for(int j=i+1 ; j<n ; j++){
                int  w = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,w});
                adj[j].push_back({i,w});
            }
        }
        int mstSUM = 0;
        vector<bool> vis(n,false);
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            int w = u.first;
            int node = u.second;
            if(vis[node]){
                continue;
            }
            vis[node] = true;
            mstSUM += w;
            for(auto &neighbor : adj[node]){
                int nNode = neighbor.first;
                int wt = neighbor.second;
                if(!vis[nNode]){
                    pq.push({wt,nNode});
                }
            }
        }
        return mstSUM;
    }
};