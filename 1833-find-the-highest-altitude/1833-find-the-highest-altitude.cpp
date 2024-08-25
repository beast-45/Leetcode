class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ini = 0 ;
        int maxgain = 0;
        for(int i=0 ; i<n ; i++)
        {
            ini += gain[i];
            maxgain = max(maxgain,ini);
        }
        return maxgain;
        
    }
};