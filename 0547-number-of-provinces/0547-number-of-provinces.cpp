class Solution {
public:
    void dfs(int i , int n , vector<vector<int>> &mat , vector<bool> &vis){
        vis[i] = true;
        for(int j=0 ; j<n ; j++){
            if(mat[i][j] == 1 && !vis[j]){
                dfs(j,n,mat,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() , count = 0;
        vector<bool> vis(n,false);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,n,isConnected,vis);
                count += 1;
            }
        }
        return count;
    }
};