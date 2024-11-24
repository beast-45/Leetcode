class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int smallest = INT_MAX;
        long long sum = 0;
        int negativeCount = 0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(matrix[i][j] < 0) negativeCount += 1;
                smallest = min(smallest , abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
            }
        }
        if(negativeCount % 2 == 0)
        {
            return sum;
        }
        else return sum - (2*smallest);
    }
};