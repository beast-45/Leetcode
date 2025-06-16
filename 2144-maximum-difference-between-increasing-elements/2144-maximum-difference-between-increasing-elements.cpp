class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size() , maxDiff = -1 , minVal = nums[0];
        for(int i=1 ; i<n ; i++){
            if(nums[i] > minVal){
                maxDiff = max(maxDiff,nums[i]-minVal);
            }else{
                minVal = nums[i];
            }
        }
        return maxDiff;
    }
};