class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        vector<int> parity(n);
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        return true;
    }
};