class Solution {
public:
    int dfs(vector<vector<int>> &adj , int currentNode , int parent , vector<bool> &hasApple){
        int time = 0;
        for(int &child : adj[currentNode]){
            if(child == parent){
                continue;
            }
            int timeTakenByChild = dfs(adj ,child , currentNode , hasApple);
            if(timeTakenByChild > 0 || hasApple[child]){
                time += (timeTakenByChild + 2);
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj , 0 , -1 , hasApple);
    }
};