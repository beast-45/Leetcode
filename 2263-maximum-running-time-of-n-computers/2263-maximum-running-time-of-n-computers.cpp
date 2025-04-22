class Solution {
public:
    typedef long long ll;
    bool check(long long time , long long n , vector<int>& batteries){
        ll runTime = 0;
        for(int &bat : batteries){
            runTime += min(time,(ll)bat);
        }
        return runTime >= time*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = INT_MAX;
        ll capacity = 0;
        for(int &battery : batteries){
            l = min(l,(ll)battery);
            capacity += battery;
        }
        ll r = capacity/n;
        ll result = 0;
        while(l <= r){
            ll mid = l+(r-l)/2;
            if(check(mid,n,batteries)){
                result = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return result;
    }
};