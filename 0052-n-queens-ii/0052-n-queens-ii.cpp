class Solution {
public:
    bool check(vector<string> &board , int row , int col , int n){
        for(int r=row-1 ; r>=0 ; r--){
            if(board[r][col] == 'Q'){
                return false;
            }
        }
        int c = col;
        for(int r=row-1 ; r>=0 ; r--){
            c += 1;
            if(c<n && board[r][c] == 'Q'){
                return false;
            }
        }
        c = col;
        for(int r=row-1 ; r>=0 ; r--){
            c -= 1;
            if(c>=0 && board[r][c] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board , int row , int n , int &count){
        if(row >= n){
            count += 1;
            return;
        }
        for(int col=0 ; col<n ; col++){
            if(check(board,row,col,n)){
                board[row][col] = 'Q';
                solve(board,row+1,n,count);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n,string(n,'.'));
        solve(board,0,n,count);
        return count;
    }
};