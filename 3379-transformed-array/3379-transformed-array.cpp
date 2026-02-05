class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0 ; i<n ; i++){
            int moves = nums[i] % n;
            int newIdx = (i + moves) % n;
            if(newIdx < 0) newIdx += n;
            result[i] = nums[newIdx];
        }
        return result;
    }
};