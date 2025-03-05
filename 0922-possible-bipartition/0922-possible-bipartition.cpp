class Solution {
public:
    bool bfs(unordered_map<int,vector<int>> &adj , int node , vector<int> &like){
        queue<int> q;
        like[node] = 0;
        q.push(node);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(like[v] == like[u]){
                    return false;
                }
                if(like[v] == -1){
                    like[v] = 1-like[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> like(n+1,-1);
        unordered_map<int,vector<int>> adj;
        for(auto &dis : dislikes){
            int a = dis[0];
            int b = dis[1];
            adj[a].push_back(b);   // a--->b
            adj[b].push_back(a);   // b--->a
        }
        for(int i=1 ; i<=n ; i++){
            if(like[i] == -1){
                if(!bfs(adj , i , like)){
                    return false;
                }
            }
        }
        return true;
    }
};