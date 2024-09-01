class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int s = original.size();
        vector<vector<int>> matrix(m , vector<int>(n));
        if(original.size() != m*n) return {};
        for(int i=0 ; i<s ; i++)
        {
            int r = i/n;
            int c = i%n;
            matrix[r][c] = original[i];

        }
        return matrix;
        
    }
};