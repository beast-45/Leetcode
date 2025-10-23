class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);
        for(auto &trip : trips){
            int passengers = trip[0] , l = trip[1] , r = trip[2];
            diff[l] += passengers;
            diff[r] -= passengers;
        }
        int current = 0;
        for(int i=0 ; i<1001; i++){
            current += diff[i];
            if(current > capacity) return false;
        }
        return true;
    }
};