class Solution {
public:
    bool check(int mid , vector<int> &bloomDay , int m , int k){
        int bqets = 0;
        int count = 0;
        for(int &bloom : bloomDay){
            if(bloom <= mid){
                count += 1;
                if(count == k){
                    bqets += 1;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return bqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()){
            return -1;
        }
        int l = INT_MAX;
        int r = INT_MIN;
        for(int &bloom : bloomDay){
            l = min(l,bloom);
            r = max(r,bloom);
        }
        int result = -1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(check(mid,bloomDay,m,k)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return result;
    }
};