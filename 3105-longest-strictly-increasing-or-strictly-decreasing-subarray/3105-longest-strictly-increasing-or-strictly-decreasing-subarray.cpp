class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxIncreasingSubarray = 1;
        int maxDecreasingSubarray = 1;
        int iTemp = 1;
        int dTemp = 1;
        for(int i=1 ; i<n ; i++){
            if(nums[i] > nums[i-1]){
                iTemp += 1;
                maxIncreasingSubarray = max(maxIncreasingSubarray , iTemp);
            }
            else{
                iTemp = 1;
            }
            if(nums[i] < nums[i-1]){
                dTemp += 1;
                maxDecreasingSubarray = max(maxDecreasingSubarray , dTemp);
            }
            else{
                dTemp = 1;
            }
        }  
        return max(maxIncreasingSubarray,maxDecreasingSubarray);      
    }
};