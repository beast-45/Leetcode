class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiOrder;

        int id = 0;
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;

        while(top <= down && left <= right)
        {
            if(id == 0)
            {
                for(int i=left ; i<=right ; i++)
                {
                    spiOrder.push_back(matrix[top][i]);
                }
                top++;
            }
            if(id == 1)
            {
                for(int i=top ; i<=down ; i++)
                {
                    spiOrder.push_back(matrix[i][right]);
                }
                right--;
            }
            if(id == 2)
            {
                for(int i=right ; i>=left ; i--)
                {
                    spiOrder.push_back(matrix[down][i]);
                }
                down--;
            }
            if(id == 3)
            {
                for(int i=down ; i>=top ; i--)
                {
                    spiOrder.push_back(matrix[i][left]);
                }
                left++;
            }
            id = (id+1)%4;
        }
        return spiOrder;
    }
};