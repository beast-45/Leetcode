class Solution {
public:
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    int dfs(int i , int j , int n , int id , vector<vector<int>> &grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] != 1){
            return 0;
        }
        int area = 1;
        grid[i][j] = id;
        for(auto &[di,dj] : directions){
            int ni = i + di;
            int nj = j + dj;
            area += dfs(ni,nj,n,id,grid);
        }
        return area;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size() , id = 2;
        unordered_map<int,int> idToArea;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 1){
                    int area = dfs(i,j,n,id,grid);
                    idToArea[id] = area;
                    id++;
                }
            }
        }
        int largest = 0 , zeroes = 0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(grid[i][j] == 0){
                    zeroes += 1;
                    unordered_set<int> alreadyConnected;
                    int area = 1;
                    for(auto &[di,dj] : directions){
                        int ni = i + di;
                        int nj = j + dj;
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj] > 1){
                            int islandID = grid[ni][nj];
                            if(!alreadyConnected.count(islandID)) area += idToArea[islandID];
                            alreadyConnected.insert(islandID);
                        }
                    }
                    largest = max(largest,area);
                }
            }
        }
        return zeroes == 0 ? n*n : largest;
    }
};