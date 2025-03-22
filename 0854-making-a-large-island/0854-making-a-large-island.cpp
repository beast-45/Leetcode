class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , int id, int n , vector<vector<int>> &grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != 1){
            return 0;
        }
        int area = 1;
        grid[i][j] = id;
        for(vector<int> &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            area += dfs(ni,nj,id,n,grid);
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> mp;
        int id = 2;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,id,n,grid);
                    mp[id] = area;
                    id++;
                }
            }
        }
        int largestIsland = 0;
        bool zero = false;
        for(int i=0 ; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j]==0){
                    zero = true;
                    unordered_set<int> alreadyAdded;
                    int area = 1;
                    for(vector<int> &direction : directions){
                        int ni = i + direction[0];
                        int nj = j + direction[1];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] > 1){
                            int islandID = grid[ni][nj];
                            if(alreadyAdded.find(islandID) == alreadyAdded.end()){
                                area += mp[islandID];
                                alreadyAdded.insert(islandID);
                            }
                        }
                    }
                    largestIsland = max(largestIsland,area);
                }
            }
        }
        if(!zero){
            return n*n;
        }
        return largestIsland;
    }
};