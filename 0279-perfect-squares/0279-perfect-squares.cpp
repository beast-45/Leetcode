class Solution {
public:
    int t[10001];
    int solve(int n)
    {
        if(n==0) return 0;
        int minCount = INT_MAX;
        if(t[n] != -1) return t[n];
        for(int i=1 ; i*i<=n ; i++)
        {
            int result = 1 + solve(n-i*i);
            minCount = min(minCount , result);
        }
        return t[n] = minCount;
    }
    int numSquares(int n) {
        memset(t , -1 , sizeof(t));
        return solve(n);
    }
};