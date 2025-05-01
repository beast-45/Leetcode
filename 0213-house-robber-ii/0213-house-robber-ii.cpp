class Solution {
public:
    int solve(int index , int n , vector<int> &nums , vector<int> &dp){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int steal = nums[index] + solve(index+2,n,nums,dp);
        int skip = solve(index+1,n,nums,dp);
        return dp[index] = max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(n+1,-1);
        int startFromFirst = solve(0,n-1,nums,dp);
        dp.assign(n,-1);
        int startFromSecond = solve(1,n,nums,dp);
        return max(startFromFirst,startFromSecond);
    }
};