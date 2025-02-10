class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , vector<int> &nums1 , vector<int> &nums2 , int m , int n){
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(nums1[i] == nums2[j]){
            return dp[i][j] = 1 + solve(i+1 , j+1 , nums1 , nums2 , m , n);
        }
        else{
            return dp[i][j] = max(solve(i+1 , j , nums1 , nums2 , m , n) , solve(i , j+1 , nums1 , nums2 , m , n));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , nums1 , nums2 , m , n);
    }
};