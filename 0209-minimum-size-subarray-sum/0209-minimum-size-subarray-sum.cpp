class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0 , j=0 , sum = 0;
        int minL = INT_MAX;

        while(j < n)
        {
            sum += nums[j];
            while(sum >= target)
            {
                minL = min(minL , j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minL == INT_MAX ? 0 : minL;  
    }
};