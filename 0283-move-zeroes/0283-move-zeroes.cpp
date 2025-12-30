class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() , i = 0;
        for(int j=0 ; j<n ; j++){
            if(nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
        }
        while(i<n){
            nums[i] = 0;
            i++;
        }
    }
};