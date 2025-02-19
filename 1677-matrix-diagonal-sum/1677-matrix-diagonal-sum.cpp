class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==1){
            return mat[0][0];
        }
        int primaryDiagonalSum = 0;
        int secondaryDiagonalSum = 0;
        for(int i=0 ; i<n ; i++){
            primaryDiagonalSum += mat[i][i];
        }
        int row = 0;
        int col = n-1;
        while(col>=0){
            secondaryDiagonalSum += mat[row][col];
            row += 1;
            col -= 1;
        }
        if(n % 2 != 0){
            secondaryDiagonalSum -= mat[n/2][n/2];
        }
        return primaryDiagonalSum + secondaryDiagonalSum;
        
    }
};