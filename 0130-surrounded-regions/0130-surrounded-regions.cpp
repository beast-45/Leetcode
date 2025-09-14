class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i , int j , int m , int n , vector<vector<char>> &board){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] != 'O'){
            return;
        }
        board[i][j] = '#';
        for(vector<int> direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            dfs(ni,nj,m,n,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int col=0 ; col<n ; col++){
            if(board[0][col] == 'O'){
                dfs(0,col,m,n,board);
            }
            if(board[m-1][col] == 'O'){
                dfs(m-1,col,m,n,board);
            }
        }
        for(int row=0 ; row<m ; row++){
            if(board[row][0] == 'O'){
                dfs(row,0,m,n,board);
            }
            if(board[row][n-1] == 'O'){
                dfs(row,n-1,m,n,board);
            }
        }
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                board[i][j] == '#' ? board[i][j] = 'O' : board[i][j] = 'X';
            }
        }
    }
};