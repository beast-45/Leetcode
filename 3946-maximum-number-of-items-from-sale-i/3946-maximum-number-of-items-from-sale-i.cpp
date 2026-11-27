class Solution {
public:
    int solve(int n , int budget , int minP , vector<vector<int>> &items , vector<int> &fc , vector<vector<int>> &dp){
        if(n==0){
            return budget/minP;
        }
        if(dp[n-1][budget] != -1) return dp[n-1][budget];
        int take = 0;
        int price = items[n-1][1];
        if(price <= budget){
            take = 1 + fc[n-1] + solve(n-1,budget-price,minP,items,fc,dp);
        }
        int skip = solve(n-1,budget,minP,items,fc,dp);
        return dp[n-1][budget] = max(take,skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minP = INT_MAX;
        vector<vector<int>> dp(n+1,vector<int>(budget+1,-1));
        vector<int> freeCopies(n);
        for(int i=0 ; i<n ; i++){
            int copies = 0;
            for(int j=0 ; j<n ; j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0] == 0) copies += 1;
            }
            freeCopies[i] = copies;
            minP = min(minP,items[i][1]);
        }
        return solve(n,budget,minP,items,freeCopies,dp);
    }
};