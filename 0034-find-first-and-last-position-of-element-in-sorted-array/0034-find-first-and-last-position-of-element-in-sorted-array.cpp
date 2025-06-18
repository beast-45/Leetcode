class Solution {
public:
    void firstPosition(vector<int> &nums , int target , vector<int> &result){
        int l = 0 , r = nums.size()-1;
        while(l<=r){
            int mid =  l+(r-l)/2;
            if(nums[mid] == target){
                result[0] = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
    }
    void lastPosition(vector<int> &nums , int target , vector<int> &result){
        int l = 0 , r = nums.size() - 1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid] ==  target){
                result[1] = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target) r = mid-1;
            else l = mid+1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.empty()) return result;
        firstPosition(nums,target,result);
        lastPosition(nums,target,result);
        return result; 
    }
};