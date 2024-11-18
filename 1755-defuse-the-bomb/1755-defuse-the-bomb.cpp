class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n,0);
        if(k == 0) return result;

        int i = -1 , j = -1;
        if(k > 0)
        {
            i = 1;
            j = k;
        }
        else
        {
            i = n - abs(k);
            j = n - 1;
        }

        int winSum = 0;
        for(int ptr=i ; ptr<=j ; ptr++)
        {
            winSum += code[ptr];
        }

        for(k=0 ; k<n ; k++)
        {
            result[k] = winSum;
            winSum -= code[i%n];
            i++;
            winSum += code[(j+1)%n];
            j++;
        }
        return result;
    }
};