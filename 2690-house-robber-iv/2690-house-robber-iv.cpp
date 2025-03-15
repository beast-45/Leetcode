class Solution {
public:
    bool canSteal(vector<int> &nums , int mid , int k){
        int houses = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] <= mid){
                houses++;
                i++;
            }
        }
        return houses >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int start = *min_element(begin(nums),end(nums));
        int endd  = *max_element(begin(nums),end(nums));
        int result = endd;
        while(start<=endd){
            int mid = start+(endd-start)/2;
            if(canSteal(nums,mid,k)){
                result = mid;
                endd = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return result;
    }
};