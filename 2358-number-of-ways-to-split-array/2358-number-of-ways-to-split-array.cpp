class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        long long sum = 0;
        for(auto &num : nums)
        {
            sum += num;
        }

        long long preSum  = 0;
        long long postSum = 0;
        for(int i=0 ; i<n-1 ; i++)
        {
            preSum  += nums[i];
            postSum  = sum - preSum;
            if(preSum >= postSum) count += 1;
        }
        return count; 
    }
};