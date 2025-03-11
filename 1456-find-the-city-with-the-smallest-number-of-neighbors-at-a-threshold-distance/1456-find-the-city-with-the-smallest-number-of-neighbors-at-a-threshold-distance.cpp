class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e5));
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            mat[u][v] = w;
            mat[v][u] = w;
        }
        for(int via=0 ; via<n ; via++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    mat[i][j] = min(mat[i][j] , mat[i][via]+mat[via][j]);
                }
            }
        }
        int city = -1;
        int minCount = INT_MAX;
        for(int u=0 ; u<n ; u++){
            int count = 0;
            for(int v=0 ; v<n ; v++){
                if(u != v && mat[u][v] <= distanceThreshold){
                    count += 1;
                }
            }
            if(count <= minCount){
                minCount = count;
                city = u;
            }
        }
        return city;   
    }
};