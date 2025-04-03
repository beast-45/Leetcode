class Solution {
public:
    int total;
    int solve(int index , int sum , int target , int n , vector<int> &nums , vector<vector<int>> &dp){
        if(index == n){
            return sum == target ? 1 : 0;
        }
        if(dp[index][sum+total] != -1){
            return dp[index][sum+total];
        }
        int add = solve(index+1,sum+nums[index],target,n,nums,dp);
        int sub = solve(index+1,sum-nums[index],target,n,nums,dp);
        return dp[index][sum+total] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        total = accumulate(begin(nums),end(nums),0);
        vector<vector<int>> dp(n,vector<int>(2001,-1));
        return solve(0,0,target,n,nums,dp); 
    }
};