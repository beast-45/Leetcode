class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0 ; i<m ; i++){
            if(target >= matrix[i][0] && target <= matrix[i][n-1]){
                int l = 0;
                int r = n-1;
                while(l <= r){
                    int mid = l+(r-l)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid] > target){
                        r = mid-1;
                    }
                    else{
                        l = mid+1;
                    }
                }
            }
        }
        return false; 
    }
};