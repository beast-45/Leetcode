class Solution {
public:
    int m,n;
    vector<pair<int,int>> directions{{1,0},{-1,0},{0,-1},{0,1}};
    bool dfs(int i , int j , int index , string &word , vector<vector<char>> &board , vector<vector<bool>> &vis){
        if(index == word.length()) return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] != word[index] || vis[i][j]) return false;
        vis[i][j] = true;
        for(auto &[di,dj] : directions){
            int ni = i + di , nj = j + dj;
            if(dfs(ni,nj,index+1,word,board,vis)) return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size() , n = board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,word,board,vis)) return true;
                }
            }
        }
        return false;
    }
};
