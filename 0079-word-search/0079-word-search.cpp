class Solution {
public:
    int m,n;
    vector<vector<bool>> vis;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(int i , int j , int index , string &word , vector<vector<char>> &board){
        if(index == word.length()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] != word[index] || vis[i][j]){
            return false;
        }
        vis[i][j] = true;
        for(auto &direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            if(dfs(ni,nj,index+1,word,board)){
                return true;
            }
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vis.resize(m,vector<bool>(n,false));
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,0,word,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};