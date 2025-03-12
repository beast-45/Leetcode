class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj , int u , vector<bool> &vis , int &score){
        vis[u] = true;
        for(auto &neighbor : adj[u]){
            int nNode = neighbor.first;
            int distance = neighbor.second;
            score = min(score,distance);
            if(!vis[nNode]){
                dfs(adj , nNode , vis , score);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1,false);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        int score = INT_MAX;
        dfs(adj , 1 , vis , score);
        return score;
    }
};