class Solution {
public:
    void dfs(vector<vector<int>> &isConnected , int u , vector<bool> &vis){
        vis[u] = true;
        for(int v=0 ; v<isConnected.size() ; v++){
            if(!vis[v] && isConnected[u][v] == 1){
                dfs(isConnected , v , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int count = 0;
        for(int u=0 ; u<n ; u++){
            if(!vis[u]){
                dfs(isConnected , u , vis);
                count += 1;
            }
        }
        return count;
    }
};