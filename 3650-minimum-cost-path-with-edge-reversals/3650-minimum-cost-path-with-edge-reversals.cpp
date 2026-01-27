class Solution {
public:
    typedef pair<int,int> P;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<P>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],2*e[2]});
        }
        vector<int> result(n,INT_MAX);
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,0});    // {w,u};
        result[0] = 0;
        while(!pq.empty()){
            auto [weight,node] = pq.top();
            pq.pop();
            for(auto &neighbor : adj[node]){
                int nNode = neighbor.first , nWeight = neighbor.second;
                if(weight + nWeight < result[nNode]){
                    result[nNode] = weight + nWeight;
                    pq.push({result[nNode],nNode});
                }
            }
        }
        return result[n-1] == INT_MAX ? -1 : result[n-1];  
    }
};