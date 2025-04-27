class Solution {
public:
    using LL = long long;
    int dfs(int bomb , vector<bool> &vis , vector<vector<int>> &adj){
        int dBombs = 1;
        vis[bomb] = true;
        for(int &nBomb : adj[bomb]){
            if(!vis[nBomb]){
                dBombs += dfs(nBomb,vis,adj);
            }
        }
        return dBombs;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(i == j) continue;
                LL x1 = bombs[i][0] , y1 = bombs[i][1] , r1 = bombs[i][2];
                LL x2 = bombs[j][0] , y2 = bombs[j][1];
                LL d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if(d <= r1*r1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n,false);
        int maxD = 0;
        for(int i=0 ; i<n ; i++){
            vis.assign(n,false);
            maxD = max(maxD,dfs(i,vis,adj));
        }
        return maxD;
    }
};