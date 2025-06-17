class Solution {
public:
    void bfs(int u , int n , int &sc ,vector<vector<int>> &adj){
        vector<int> count(n,0);
        vector<bool> vis(n,false);
        queue<pair<int,int>> q;
        q.push({u,-1});
        vis[u] = true;
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
        int shortest = INT_MAX;
        for(int i=0 ; i<n ; i++){
            bfs(i,n,shortest,adj);
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};