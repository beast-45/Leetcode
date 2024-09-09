class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>spiMat(n , vector<int>(n));
        int id = 0;
        int top = 0;
        int down = n-1;
        int left = 0;
        int right = n-1;
        int e = 1;
        while(top <= down && left <= right)
        {
            if(id == 0)
            {
                for(int i=left ; i<=right ; i++)
                {
                    spiMat[top][i]=e;
                    e += 1;
                }
                top++;
            }
            if(id == 1)
            {
                for(int i=top ; i<=down ; i++)
                {
                    spiMat[i][right] = e;
                    e += 1;
                }
                right--;
            }
            if(id == 2)
            {
                for(int i=right ; i>=left ; i--)
                {
                    spiMat[down][i] = e;
                    e += 1;
                }
                down--;
            }
            if(id == 3)
            {
                for(int i=down ; i>=top ; i--)
                {
                    spiMat[i][left] = e;
                    e += 1;
                }
                left++;
            }
            id = (id+1)%4;
        }
        return spiMat;
    }
};