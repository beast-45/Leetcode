class Solution {
public:
    int dfs(int node , int parentNode , vector<vector<int>> &adj , vector<bool> &hasApple){
        int time = 0;
        for(auto &childNode : adj[node]){
            if(childNode == parentNode) continue;
            int timeTakenByChildTCA = dfs(childNode,node,adj,hasApple);   //timeTakenByChildToCollectApples
            if(timeTakenByChildTCA > 0 || hasApple[childNode]){
                time += timeTakenByChildTCA + 2;
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};