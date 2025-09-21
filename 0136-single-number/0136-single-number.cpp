class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        for(int &n : nums){
            num ^= n;
        }
        return num;
    }
};