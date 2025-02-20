class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSubSum = INT_MIN;
        for(int &num : nums){
            sum += num;
            maxSubSum = max(maxSubSum,sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSubSum;
    }
};