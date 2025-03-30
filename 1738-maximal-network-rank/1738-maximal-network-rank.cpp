class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        vector<vector<bool>> common(n,vector<bool>(n,false));
        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            indegree[u]++;
            indegree[v]++;
            common[u][v] = true;
            common[v][u] = true;
        }
        int maxRank = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                int totalRank = indegree[i] + indegree[j];
                if(common[i][j]){
                    totalRank -= 1;
                }
                maxRank = max(maxRank,totalRank);
            }
        }
        return maxRank;
    }
};