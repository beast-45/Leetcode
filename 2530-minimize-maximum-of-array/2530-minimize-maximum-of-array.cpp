class Solution {
public:
    bool check(int maxAllowed , vector<int> &numbers){
        vector<long long> nums(begin(numbers),end(numbers));
        int n = nums.size();
        for(int i=0 ; i<n-1 ; i++){
            if(nums[i] > maxAllowed){
                return false;
            }
            long long buffer = maxAllowed-nums[i];
            nums[i] += buffer;
            nums[i+1] -= buffer;
        }
        return nums[n-1] <= maxAllowed;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = INT_MAX;
        int r = INT_MIN;
        for(int &num : nums){
            l = min(l,num);
            r = max(r,num);
        }
        int minMax = INT_MAX;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(check(mid,nums)){
                minMax = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return minMax;
    }
};