class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m = original.size();
        int n = source.size();
        vector<vector<int>> adjMatrix(26,vector<int>(26,1e9));
        for(int i=0 ; i<m ; i++){
            int u = original[i]-'a';
            int v = changed[i]-'a';
            int w = cost[i];
            adjMatrix[u][v] = min(adjMatrix[u][v],w);
        }
        for(int k=0 ; k<26 ; k++){
            for(int i=0 ; i<26 ; i++){
                for(int j=0 ; j<26 ; j++){
                    adjMatrix[i][j] = min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }
        long long minCost = 0;
        for(int i=0 ; i<n ;i++){
            if(source[i] == target[i]){
                continue;
            }
            else{
                int u = source[i]-'a';
                int v = target[i]-'a';
                int w = adjMatrix[u][v];
                if(w >= 1e9){
                    return -1;
                }
                minCost += w;
            }
        }
        return minCost;
    }
};