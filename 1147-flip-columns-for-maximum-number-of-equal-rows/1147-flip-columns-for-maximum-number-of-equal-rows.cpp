class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRow = 0;
        
        for(auto &currRow : matrix)
        {
            vector<int> inverted(n);
            for(int col=0 ; col<n ; col++)
            {
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }
            int count = 0;
            for(auto &row : matrix)
            {
                if(row == currRow || row == inverted) count += 1;
            }
            maxRow = max(maxRow , count);
        }
        return maxRow;
    }
};