class Solution {
public:
    int dfs(vector<vector<int>> &adj , int u , vector<bool> &vis){
        int bombs = 1;
        vis[u] = true;
        for(int &v : adj[u]){
            if(!vis[v]){
                bombs += dfs(adj , v , vis);
            }
        }
        return bombs;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == j) continue;
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r1 = bombs[i][2];
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];
                long long d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if(d<=r1*r1){
                    adj[i].push_back(j);
                } 
            }
        }
        int maxBombs = 0;
        for(int i=0 ; i<n ; i++){
            vector<bool> vis(n,false);
            int bombs = dfs(adj , i , vis);
            maxBombs = max(maxBombs,bombs);
        }
        return maxBombs;
    }
};