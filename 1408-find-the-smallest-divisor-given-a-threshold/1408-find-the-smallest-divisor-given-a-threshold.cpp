class Solution {
public:
    bool check(int div , int threshold , vector<int> nums){
        int sum = 0;
        for(int &num : nums){
            num % div == 0 ? sum+=num/div : sum+=num/div+1;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(begin(nums),end(nums));
        while(l <= r){
            int mid = l+(r-l)/2;
            if(check(mid,threshold,nums)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};