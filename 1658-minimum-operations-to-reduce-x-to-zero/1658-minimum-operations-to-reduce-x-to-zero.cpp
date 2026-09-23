class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(begin(nums),end(nums),0);
        int target = total - x;
        if(x > total) return -1;
        if(x == total) return n;
        int l = 0 , r = 0 , maxLen = -1;
        int winSum = 0;
        for(int r=0 ; r<n ; r++){
            winSum += nums[r];
            while(winSum > target && l <= r){
                winSum -= nums[l];
                l += 1;
            }
            if(winSum == target){
                maxLen = max(maxLen,r-l+1);
            }
        }
        return maxLen == -1 ? -1 : n-maxLen;
    }
};