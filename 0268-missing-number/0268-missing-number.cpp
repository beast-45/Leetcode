class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int ts = n*(n-1)/2;
        int os = accumulate(begin(nums),end(nums),0);
        return ts-os;
    }
};