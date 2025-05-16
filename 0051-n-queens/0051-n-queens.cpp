class Solution {
public:
    vector<vector<string>> result;
    bool check(int row , int col , int n , vector<string> &board){
        for(int r=row-1 ; r>=0 ; r--){
            if(board[r][col] == 'Q'){
                return false;
            }
        }
        int c = col;
        for(int r=row-1 ; r>=0 ; r--){
            c--;
            if(c>=0 && board[r][c] == 'Q'){
                return false;
            }
        }
        c = col;
        for(int r=row-1 ; r>=0 ; r--){
            c++;
            if(c<n && board[r][c] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(int row , int n , vector<string> &board){
        if(row >= n){
            result.push_back(board);
            return;
        }
        for(int col=0 ; col<n ; col++){
            if(check(row,col,n,board)){
                board[row][col] = 'Q';
                solve(row+1,n,board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        solve(0,n,board);
        return result;
    }
};