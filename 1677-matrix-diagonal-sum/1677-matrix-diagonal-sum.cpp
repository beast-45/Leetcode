class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        if(n==1) return mat[0][0];
        int sum = 0; 
        for(int i=0 ; i<n ; i++)
        {
            sum += mat[i][i];
        }
        int x = 0;
        int y = n-1;
        while(y>=0)
        {
            sum+= mat[x][y];
            x++;
            y--;
        }
        if(n> 2 && n%2 != 0) sum -= mat[n/2][n/2];
        return sum;
        }
};