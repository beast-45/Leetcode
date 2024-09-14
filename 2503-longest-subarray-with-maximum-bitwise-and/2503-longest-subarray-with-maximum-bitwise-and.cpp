class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxAnd = nums[0];
        for(int i=1 ; i<n ; i++)
        {
            maxAnd = max(maxAnd , nums[i]);
        }
        int maxlen = 0;
        int len = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] == maxAnd)
            {
                len += 1;
                maxlen = max(maxlen , len);
            }
            if(nums[i] != maxAnd) len = 0;
        }
        return maxlen;
        
    }
};