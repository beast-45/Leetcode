class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxRank = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int iRank = adj[i].size();
                int jRank = adj[j].size();
                int rank = iRank + jRank;
                if(adj[j].find(i) != adj[j].end()){
                    rank -= 1;
                }
                maxRank = max(maxRank,rank);
            }
        }
        return maxRank;
    }
};