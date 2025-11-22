class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int num : nums){
            if(num % 3 != 0) ops += 1;
        }
        return ops;
    }
};