class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj , int u , vector<bool> &vis , long long &count){
        vis[u] = true;
        count += 1;
        for(int &v : adj[u]){
            if(!vis[v]){
                dfs(adj , v , vis , count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        unordered_map<int,vector<int>> adj;
        long long dis = 0;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long size = n;
        for(int i=0 ; i<n ; i++){
            long long count = 0;
            if(!vis[i]){
                dfs(adj , i , vis , count);
                size -= count;
                dis += size*count;
            }
        }
        return dis;
    }
};