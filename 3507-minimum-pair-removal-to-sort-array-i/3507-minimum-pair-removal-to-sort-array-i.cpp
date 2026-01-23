class Solution {
public:
    int findMinPairSum(vector<int> &nums){
        int minSum = INT_MAX;
        int index = -1;
        for(int i=0 ; i<nums.size()-1 ; i++){
            int sum = nums[i] + nums[i+1];
            if(sum < minSum){
                minSum = sum;
                index = i;
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while(!is_sorted(begin(nums),end(nums))){
            int index = findMinPairSum(nums);
            nums[index] = nums[index] + nums[index+1];
            nums.erase(begin(nums)+index+1);
            ops += 1;
        }
        return ops;
    }
};