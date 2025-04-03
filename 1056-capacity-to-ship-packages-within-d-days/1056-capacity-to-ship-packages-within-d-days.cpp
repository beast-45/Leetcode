class Solution {
public:
    bool check(int capacity , vector<int> &weights , int days){
        int day = 1;
        int load = 0;
        for(int wt : weights){
            if(load + wt > capacity){
                day += 1;
                load = wt;
            }
            else{
                load += wt;
            }
        }
        return day <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = INT_MIN;
        int h = 0;
        for(int i=0 ; i<n ; i++){
            l = max(l,weights[i]);
            h += weights[i];
        }
        while(l<=h){
            int mid = l + (h - l) / 2;
            if(check(mid,weights,days)){
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};