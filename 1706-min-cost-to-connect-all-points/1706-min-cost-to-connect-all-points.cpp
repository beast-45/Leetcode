class Solution {
public:
    using P = pair<int,int>;
    int primsAlgo(int n , vector<vector<P>> &adj){
        int mstSum = 0;
        vector<bool> vis(n,false);   // already in MST
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost,node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            mstSum += cost;
            vis[node] = true;
            for(auto &[nNode,nCost] : adj[node]){
                if(!vis[nNode]) pq.push({nCost,nNode});
            }
        }
        return mstSum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<P>> adj(n);
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int d = abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        return primsAlgo(n,adj);
    }
};
