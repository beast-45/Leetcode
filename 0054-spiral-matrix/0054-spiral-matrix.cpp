class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size() , cols = matrix[0].size();
        int top = 0 , down = rows-1 , left = 0 , right = cols-1 , direction = 0;
        vector<int> result;
        while(left <= right && top <= down){
            if(direction == 0){
                for(int i=top ; i<=right ; i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(direction == 1){
                for(int i=top ; i<=down ; i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(direction == 2){
                for(int i=right ; i>=left ; i--){
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            if(direction == 3){
                for(int i=down ; i>=top ; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return result;
    }
};
