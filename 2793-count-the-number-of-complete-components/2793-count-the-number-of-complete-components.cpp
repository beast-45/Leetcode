class Solution {
public:
    void dfs(vector<vector<int>> &adj , int u , vector<int>&vis , int &nodes , int &edges){
        vis[u] = true;
        nodes++;
        for(int &v : adj[u]){
            edges++;
            if(!vis[v]){
                dfs(adj,v,vis,nodes,edges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,false);
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                int nodes = 0;
                int edges = 0;
                dfs(adj,i,vis,nodes,edges);
                if(edges/2 == nodes*(nodes-1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};