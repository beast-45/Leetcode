class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size() , smallest = INT_MAX , negatives = 0;
        long long sum = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] < 0) negatives += 1;
                smallest = min(smallest,abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(negatives % 2 == 0) return sum;
        return sum - (2*smallest);
    }
};