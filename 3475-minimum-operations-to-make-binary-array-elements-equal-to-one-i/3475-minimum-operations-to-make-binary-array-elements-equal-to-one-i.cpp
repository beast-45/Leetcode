class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;
        for(int i=0 ; i<=n-3 ; i++){
            if(nums[i] == 0){
                nums[i] = 1;
                nums[i+1] = nums[i+1] == 0 ? 1 : 0;
                nums[i+2] = nums[i+2] == 0 ? 1 : 0;
                op += 1; 
            }
        }
        int zeroCount = count(begin(nums),end(nums),0);
        return zeroCount > 0 ? -1 : op; 
    }
};