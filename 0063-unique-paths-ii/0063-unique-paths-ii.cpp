class Solution {
public:
    int solve(int i , int j , int m , int n , vector<vector<int>> &obstacleGrid , vector<vector<int>> &mem){
        if(i >= m || j >= n || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(mem[i][j] != -1){
            return mem[i][j];
        }
        
        int goRight = solve(i , j+1 , m , n , obstacleGrid , mem);
        int goDown = solve(i+1 , j , m , n , obstacleGrid , mem);

        return mem[i][j] = goRight + goDown;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> mem(m , vector<int>(n,-1));
        return solve(0 , 0 , m , n , obstacleGrid , mem);
    }
};