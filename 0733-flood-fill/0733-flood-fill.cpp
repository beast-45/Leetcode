class Solution {
public:
    void dfs(int i , int j , int m , int n , int iColor , int color , vector<vector<int>> &image , vector<pair<int,int>> &directions){
        if(i<0 || i>=m || j<0 || j>=n || image[i][j] != iColor){
            return;
        }
        image[i][j] = color;
        for(auto &[di,dj] : directions){
            int ni = i + di;
            int nj = j + dj;
            dfs(ni,nj,m,n,iColor,color,image,directions);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int iColor = image[sr][sc];
        if(iColor == color){
            return image;
        }
        vector<pair<int,int>> directions {{1,0},{-1,0},{0,1},{0,-1}};
        dfs(sr,sc,m,n,iColor,color,image,directions);
        return image;
    }
};