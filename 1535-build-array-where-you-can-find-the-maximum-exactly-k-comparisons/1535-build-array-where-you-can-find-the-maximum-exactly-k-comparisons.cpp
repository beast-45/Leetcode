class Solution {
public:
    int M = 1e9+7;
    int dp[51][51][101];
    int solve(int index , int searchCost , int maxSoFar , int n , int m , int k){
        if(index == n){
            return searchCost == k ? 1 : 0;
        }
        if(dp[index][searchCost][maxSoFar] != -1){
            return dp[index][searchCost][maxSoFar];
        }
        int result = 0;
        for(int i=1 ; i<=m ; i++){
            if(i > maxSoFar){
                result = (result + solve(index+1 , searchCost+1 , i , n , m , k)) % M;;
            }
            else{
                result = (result + solve(index+1 , searchCost , maxSoFar , n , m , k)) % M;
            }
        }
        return dp[index][searchCost][maxSoFar] = result % M;
    }
    int numOfArrays(int n, int m, int k) {
        vector<int> nums(n);
        memset(dp,-1,sizeof(dp));
        return solve(0 , 0 , 0 , n , m , k);
        
    }
};