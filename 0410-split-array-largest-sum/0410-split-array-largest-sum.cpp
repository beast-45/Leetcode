class Solution {
public:
    bool check(int mid , int k , vector<int> &nums){
        int count = 1 , sum = 0;
        for(int &num : nums){
            if(num > mid) return false;
            if(sum+num > mid){
                count += 1;
                sum = num;
                if(count > k) return false;
            }else{
                sum += num;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size() , l = INT_MIN , r = 0 , result = 0;
        for(int i=0 ; i<n ; i++){
            l = max(l,nums[i]);
            r += nums[i];
        }
        while(l <= r){
            int mid = l+(r-l)/2;
            if(check(mid,k,nums)){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return result;
    }
};