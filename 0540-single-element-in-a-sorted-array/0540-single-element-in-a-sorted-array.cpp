class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == nums[mid+1]){
                if((r-mid) % 2 == 0){
                    l = mid + 2;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if((r-mid) % 2 == 0){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return nums[r];
    }
};