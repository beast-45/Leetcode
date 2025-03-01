class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;
        for(int i=0 ; i<n-1 ; i++){
            if(op == n-1){
                break;
            }
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
                op += 1;
            }
        }
        int j = 0;
        for(int i=0 ; i<n ; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        while(j<n){
            nums[j] = 0;
            j++;
        }
        return nums;
    }
};