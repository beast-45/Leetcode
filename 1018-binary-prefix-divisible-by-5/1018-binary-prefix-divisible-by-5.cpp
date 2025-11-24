class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size() , num = 0;
        vector<bool> result(n);
        for(int i=0 ; i<n ; i++){
            num = (num*2)%5;
            num += nums[i];
            result[i] = (num % 5 == 0) ? true : false;
        }
        return result; 
    }
};