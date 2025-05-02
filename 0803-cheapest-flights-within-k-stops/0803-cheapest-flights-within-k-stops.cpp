class Solution {
public:
    using P = pair<int,int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<P>> adj(n);
        for(auto &flight : flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int> result(n,INT_MAX);
        queue<P> q;
        q.push({src,0});
        result[src] = 0;
        int stops = 0;
        while(!q.empty() && stops <= k){
            int s = q.size();
            while(s--){
                auto [node,cost] = q.front();
                q.pop();
                for(auto &[nNode,nCost] : adj[node]){
                    if(cost + nCost < result[nNode]){
                        result[nNode] = cost + nCost;
                        q.push({nNode,result[nNode]});
                    }
                }
            }
            stops++;
        }
        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};