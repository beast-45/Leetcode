class Solution {
public:
    void dfs(vector<vector<int>> &adj , int u , vector<bool> &vis){
        vis[u] = true;
        for(int &v : adj[u]){
            if(!vis[v]){
                dfs(adj,v,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        vis[0] = true;
        dfs(rooms,0,vis);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};