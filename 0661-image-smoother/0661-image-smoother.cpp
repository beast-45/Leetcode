class Solution {
public:
    bool valid(int i , int j , int m , int n){
        if(i>=0 && i<m && j>=0 && j<n){
            return true;
        }
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> result(m,vector<int>(n));
        vector<vector<int>> directions{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                int smooth = img[i][j];
                int count = 1;
                for(auto &direction : directions){
                    int ni = i + direction[0];
                    int nj = j + direction[1];
                    if(valid(ni,nj,m,n)){
                        smooth += img[ni][nj];
                        count += 1;
                    }
                }
                result[i][j] = smooth/count;
            }
        }
        return result;
    }
};