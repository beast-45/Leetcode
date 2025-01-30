class Solution {
public:
    int t[1001];
    int solve(vector<int>& cost, int index, int n) {
        if (index > n - 1) {
            return 0;
        }
        if (t[index] != -1) {
            return t[index];
        }

        int oneStepCost = cost[index] + solve(cost, index + 1, n);
        int twoStepCost = cost[index] + solve(cost, index + 2, n);

        return t[index] = min(oneStepCost, twoStepCost);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(t, -1, sizeof(t));
        return min(solve(cost, 1, n), solve(cost, 0, n));
    }
};