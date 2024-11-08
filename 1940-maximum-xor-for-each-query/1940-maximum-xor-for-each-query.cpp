class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int> result(n);

        int XOR = 0;
        for(int i = 0; i < n; i++) {
            XOR ^= nums[i];
        }

        int mask = ((1 << maximumBit) - 1);

        for(int i = 0; i < n; i++) {
            int k = XOR ^ mask; 
            result[i] = k;

            XOR = (XOR ^ nums[n-1-i]);
        }

        return result;


    }
};
