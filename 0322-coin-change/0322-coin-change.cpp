class Solution {
public:
    int dp[10001][13]; 
    int solve(vector<int> &coins, int amount, int idx) {
        if (amount == 0){
            return 0;
        }
        if (idx >= coins.size() || amount < 0){
            return 1e6;
        }

        if (dp[amount][idx] != -1){
            return dp[amount][idx];
        }

        int take = 1 + solve(coins, amount - coins[idx], idx);
        int skip = solve(coins, amount, idx + 1);

        return dp[amount][idx] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int minCoins = solve(coins, amount, 0);
        return (minCoins >= 1e6) ? -1 : minCoins;
    }
};