class Solution {
public:
    void bfs(int u , vector<vector<int>> &adj , int &sc){
        int n = adj.size();
        vector<int> count(n,0);
        vector<bool> vis(n,false);
        queue<pair<int,int>> q;
        vis[u] = true;
        q.push({u,-1});
        while(!q.empty()){
            auto [node,parent] = q.front();
            q.pop();
            for(int &v : adj[node]){
                if(!vis[v]){
                    count[v] = count[node] + 1;
                    q.push({v,node});
                    vis[v] = true;
                }
                else if(v != parent){
                    int cycle = count[node] + count[v] + 1;
                    sc = min(sc,cycle);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int shortestCycle = INT_MAX;
        for(int start=0 ; start<n ; start++){
            bfs(start,adj,shortestCycle);
        }
        return shortestCycle == INT_MAX ? -1 : shortestCycle;
    }
};