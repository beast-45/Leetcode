class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh += 1;
            }
        }
        int time = 0;
        while (!q.empty()){
            int s = q.size();
            bool rot = false;
            while (s--) {
                auto [i,j] = q.front();
                q.pop();
                for (auto& [di, dj] : directions){
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n &&grid[ni][nj] == 1) {
                        q.push({ni, nj});
                        grid[ni][nj] = 2;
                        rot = true;
                        fresh--;
                    }
                }
            }
            if(rot) time += 1;
        }
        return fresh == 0 ? time : -1;
    }
};