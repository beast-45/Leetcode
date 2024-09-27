class Solution {
public:
    int t[201][201];
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (t[i][j] != -1)
            return t[i][j];
        if (i == m - 1)
            return t[i][j] = grid[i][j] + solve(grid, i, j + 1, m, n);
        else if (j == n - 1)
            return t[i][j] = grid[i][j] + solve(grid, i + 1, j, m, n);
        else
            return t[i][j] = grid[i][j] + min(solve(grid, i + 1, j, m, n),
                                              solve(grid, i, j + 1, m, n));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(t, -1, sizeof(t));

        return solve(grid, 0, 0, m, n);
    }
};