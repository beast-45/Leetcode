class Solution {
public:
    int solve(int i , int j , vector<int>& nums , vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i == j) return nums[i];
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int takeI = nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int takeJ = nums[j] + min(solve(i,j-2,nums,dp),solve(i+1,j-1,nums,dp));
        return dp[i][j] = max(takeI,takeJ);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalScore = accumulate(begin(nums),end(nums),0);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int p1Score = solve(0,n-1,nums,dp);
        int p2Score = totalScore - p1Score;
        return p1Score >= p2Score;
    }
};