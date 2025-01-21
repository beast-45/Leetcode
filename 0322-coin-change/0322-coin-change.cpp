class Solution {
public:
    vector<vector<int>> t;
    int solve(vector<int> &coins , int amount , int idx){
        if(idx >= coins.size() || amount<0) return 1000000;
        if(amount == 0) return 0;

        if(t[idx][amount] != -1) return t[idx][amount];

        int take = 1 + solve(coins , amount-coins[idx] , idx);
        int skip = solve(coins , amount , idx+1);

        return t[idx][amount] = min(skip , take);
    }
    int coinChange(vector<int>& coins, int amount) {
        t = vector<vector<int>>(coins.size() , vector<int>(amount+1 , -1));
        int minCoins = solve(coins , amount , 0);
        return minCoins == 1000000 ? -1 : minCoins;
    }
};