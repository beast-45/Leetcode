class Solution {
public:
    bool dfs(int u , int currColor , vector<int> &color , vector<vector<int>> &graph){
        color[u] = currColor;
        for(int &v : graph[u]){
            if(color[v] == color[u]) return false;
            if(color[v] == -1){
                if(!dfs(v,1-currColor,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                if(!dfs(i,0,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};