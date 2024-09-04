class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int nNum = 0;
        int pNum = 0;
        for (int i = 0; i < n; i++) {
            if(nums[i] < 0) nNum++;
            if(nums[i] > 0) pNum++;
        }
        return max(pNum, nNum);
    }
};