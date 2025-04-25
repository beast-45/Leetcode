class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTri(numRows);
        for(int i=0 ; i<numRows ; i++){
            pascalTri[i].resize(i+1);
            pascalTri[i][0] = 1;
            pascalTri[i][i] = 1;
            for(int j=1 ; j<i ; j++){
                pascalTri[i][j] = pascalTri[i-1][j-1] + pascalTri[i-1][j];
            }
        }
        return pascalTri;
    }
};