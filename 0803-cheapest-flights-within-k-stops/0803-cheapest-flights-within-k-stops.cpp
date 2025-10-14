class Solution {
public:
    typedef pair<int,int> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<P>> adj(n);
        for(auto &flight : flights){
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int> result(n,INT_MAX);
        queue<P> q;
        q.push({0,src});
        result[src] = 0;
        int stops = 0;
        while(!q.empty() && stops <= k){
            int s = q.size();
            while(s--){
                auto [price,node] = q.front();
                q.pop();
                for(auto &[nNode,nPrice] : adj[node]){
                    if(price + nPrice < result[nNode]){
                        result[nNode] = price + nPrice;
                        q.push({result[nNode],nNode});
                    }
                }
            }
            stops++;
        }
        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};