class Solution {
public:
    vector<long long> dp; 
    
    long long solve(int n) {
        if (n == 1) return 1; 
        if (dp[n] != -1) return dp[n];
        return dp[n] = solve(n - 1) + 4 *(n - 1);
    }
    long long coloredCells(int n) {
        dp.resize(n + 1, -1); 
        return solve(n);
    }
};
