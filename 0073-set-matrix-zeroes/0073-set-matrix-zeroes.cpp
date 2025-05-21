class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<int> rows , cols;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i=0 ; i<rows.size() ; i++){
            for(int col=0 ; col<n ; col++){
                grid[rows[i]][col] = 0;
            }
        }
        for(int i=0 ; i<cols.size() ; i++){
            for(int row=0 ; row<m ; row++){
                grid[row][cols[i]] = 0;
            }
        }
    }
};