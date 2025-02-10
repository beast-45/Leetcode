class Solution {
public:
    int dp[301][11];
    int solve(vector<int> &jobDifficulty , int index , int days , int n){
        if(days == 1){
            int maxD = jobDifficulty[index];
            for(int i=index ; i<n ; i++){
                maxD = max(maxD , jobDifficulty[i]);
            }
            return maxD;
        }
        if(dp[index][days] != -1){
            return dp[index][days];
        }
        int maxD = jobDifficulty[index];
        int minD = INT_MAX;
        for(int i=index ; i<=n-days ; i++){
            maxD = max(maxD , jobDifficulty[i]);
            int diff = maxD + solve(jobDifficulty , i+1 , days-1 , n);
            minD = min(minD , diff);
        }
        return dp[index][days] = minD;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(jobDifficulty , 0 , d , n);
    }
};