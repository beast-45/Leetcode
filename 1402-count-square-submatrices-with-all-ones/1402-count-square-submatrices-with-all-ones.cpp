class Solution {
public:
    int solve(int i , int j , int m , int n , vector<vector<int>> &matrix , vector<vector<int>> &dp){
        if(i>=m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(matrix[i][j] == 0){
            return dp[i][j] = 0;
        }
        int right = solve(i , j+1 , m , n , matrix , dp);
        int diagonal = solve(i+1 , j+1 , m , n , matrix , dp);
        int down = solve(i+1 , j , m , n , matrix , dp);

        return dp[i][j] = 1 + min({right , diagonal , down});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m , vector<int>(n,-1));

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 1){
                    result += solve(i , j , m , n , matrix , dp);
                }
            }
        }
        return result;
    }
};