class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &flight : flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,int>> q;
        q.push({src,0});
        result[src] = 0;
        int stops = 0;
        while(!q.empty() && stops <= k){
            int s = q.size();
            while(s--){
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();
                for(auto &neighbor : adj[node]){
                    int nNode = neighbor.first;
                    int nCost = neighbor.second;
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