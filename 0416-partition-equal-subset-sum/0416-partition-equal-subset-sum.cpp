class Solution {
public:
    bool solve(int index , int sum , int target , int n , vector<int> &nums , vector<vector<int>> &dp){
        if(sum > target){
            return 0;
        }
        if(index == n){
            return sum == target ? 1 : 0;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        int take = solve(index+1,sum+nums[index],target,n,nums,dp);
        int skip = solve(index+1,sum,target,n,nums,dp);
        return dp[index][sum] = take || skip;
        
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum % 2 == 1){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(0,0,target,n,nums,dp);
    }
};