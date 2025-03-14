class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int maxCandy = *max_element(begin(candies),end(candies));
        int l = 1;
        int r = maxCandy;
        while(l <= r){
            int mid = l + (r - l) / 2;
            long long count = 0;
            for(int j=0 ; j<n ; j++){
                count += candies[j]/mid;
            }
            if(count >= k){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r;
    }
};