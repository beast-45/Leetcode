class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , int currentvalue , vector<vector<int>> &grid , vector<vector<int>> &dp){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] <= currentvalue){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxPath = 0;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            int path = dfs(ni,nj,grid[i][j],grid,dp);
            maxPath = max(maxPath,path);
        }
        return dp[i][j] = 1 + maxPath;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int longestPath = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int path = dfs(i,j,-1,matrix,dp);
                longestPath = max(longestPath,path);
            }
        }
        return longestPath;
    }
};