class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1,0);
        for(auto &booking : bookings){
            int l = booking[0]-1 , r = booking[1]-1 , seats = booking[2];
            diff[l] += seats;
            if(r+1 < n) diff[r+1] -= seats;
        }
        vector<int> result(n,0);
        result[0] = diff[0];
        for(int i=1 ; i<n ; i++){
            result[i] = diff[i] + result[i-1];
        }
        return result;
    }
};