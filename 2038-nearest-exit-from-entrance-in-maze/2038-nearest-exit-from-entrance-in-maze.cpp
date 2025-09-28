class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = true;
        int steps = 0;
        while (!q.empty()){
            int s = q.size();
            while (s--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (auto& [di, dj] : directions){
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && maze[ni][nj] == '.' && !vis[ni][nj]) {
                        if (ni == 0 || ni == m - 1 || nj == 0 || nj == n - 1){
                            return steps + 1;
                        }
                        vis[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
};