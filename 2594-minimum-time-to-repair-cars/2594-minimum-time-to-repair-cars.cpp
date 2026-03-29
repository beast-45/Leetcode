class Solution {
public:
    bool repair(vector<int> &ranks , long long mid , int cars){
        long long rcars = 0;
        for(int i=0 ; i<ranks.size() ; i++){
            rcars += sqrt(mid/ranks[i]);
        }
        return rcars >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0;
        long long maxElement = *max_element(begin(ranks),end(ranks));
        long long r = maxElement*cars*cars;
        long long result = -1;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(repair(ranks,mid,cars)){
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