class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int requiredSum = n*(n-1)/2;
        int actualSum = accumulate(begin(nums),end(nums),0);
        return requiredSum-actualSum;
    }
};