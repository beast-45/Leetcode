class Solution {
public:
    int solve(int index , int n , int k , vector<int> &nums , vector<int> &dp){
        if(index >= n) return 0;
        if(dp[index] != -1){
            return dp[index];
        }
        int result = 0 , maxElement = -1;
        for(int j=index ; j<n && j-index+1 <= k ; j++){
            maxElement = max(maxElement,nums[j]);
            result = max(result,((j-index+1)*maxElement + solve(j+1,n,k,nums,dp)));
        }
        return dp[index] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,k,arr,dp);
    }
};