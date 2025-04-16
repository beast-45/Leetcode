class Solution {
public:
    int m,n;
    vector<vector<int>> directions{{-1,1},{0,1},{1,1}};
    int dfs(int i , int j , int currentValue , vector<vector<int>> &grid , vector<vector<int>>&dp){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] <= currentValue){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int mMoves = 0;
        for(auto &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            int moves = dfs(ni,nj,grid[i][j],grid,dp);
            mMoves = max(mMoves,moves);
        }
        return dp[i][j] = 1 + mMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxMoves = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0 ; i<m ; i++){
            int moves = dfs(i,0,-1,grid,dp);
            maxMoves = max(maxMoves,moves);
        }
        return maxMoves-1;
    }
};
