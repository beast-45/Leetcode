class Solution {
public:
    int solve(int i , int j , int m , int n , vector<int> &nums1 , vector<int> &nums2 , vector<vector<int>> &dp){
        if(i==m || j==n) return -1e7;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int val = nums1[i]*nums2[j];
        int takeBoth = (nums1[i]*nums2[j]) + solve(i+1,j+1,m,n,nums1,nums2,dp);
        int take_i = solve(i,j+1,m,n,nums1,nums2,dp);
        int take_j = solve(i+1,j,m,n,nums1,nums2,dp);
        return dp[i][j] = max({val,takeBoth,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,nums1,nums2,dp);
    }
};