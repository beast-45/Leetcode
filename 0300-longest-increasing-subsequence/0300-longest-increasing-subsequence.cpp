class Solution {
public:
    int solve(int index , int n , int prevIndex , vector<int> &nums , vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        if(prevIndex != -1 && dp[index][prevIndex] != -1){
            return dp[index][prevIndex];
        }
        int take = 0;
        if(prevIndex == -1 || nums[index] > nums[prevIndex]){
            take = 1 + solve(index+1,n,index,nums,dp);
        }
        int skip = solve(index+1,n,prevIndex,nums,dp);
        return prevIndex == -1 ? max(take,skip) : dp[index][prevIndex] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,n,-1,nums,dp);
    }
};