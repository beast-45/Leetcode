class Solution {
public:
    bool check(long long mid , int n , int r , int k , vector<long long> diff){
        long long currPower = 0;
        for(int i=0 ; i<n ; i++){
            currPower += diff[i];
            if(currPower < mid){
                long long req = mid-currPower;
                if(req > k) return false;
                k -= req;
                currPower += req;
                if(i+2*r+1 < n){
                    diff[i+2*r+1] -= req;
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n,0);
        for(int i=0 ; i<n ; i++){
            diff[max(0,i-r)] += stations[i];
            if(i+r+1 < n) diff[i+r+1] -= stations[i];
        }
        long long l = INT_MAX , h = k , result = 0;
        for(int i=0 ; i<n ; i++){
            l = min(l,(long long)stations[i]);
            h += stations[i];
        }
        while(l<=h){
            long long mid = l+(h-l)/2;
            if(check(mid,n,r,k,diff)){
                result = mid;
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return result;
    }
};