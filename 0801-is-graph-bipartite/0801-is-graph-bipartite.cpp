class Solution {
public:
    bool dfs(int u , int currColor , vector<vector<int>> &adj , vector<int> &color){
        color[u] = currColor;
        for(int &v : adj[u]){
            if(color[v] == currColor) return false;
            if(color[v] == -1){
                if(!dfs(v,1-currColor,adj,color)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(!dfs(i,0,graph,color)) return false;
            }
        }
        return true;
    }
};