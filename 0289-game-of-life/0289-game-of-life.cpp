class Solution {
public:
    bool check(int i , int j , int m , int n){
        if(i<0 || i>=m || j<0 || j>=n){
            return false;
        }
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> nextState = board;
        vector<vector<int>> directions{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j]){
                    int neighboringLives = 0;
                    for(auto &direction : directions){
                        int ni = i + direction[0];
                        int nj = j + direction[1];
                        if(check(ni,nj,m,n) && board[ni][nj] == 1){
                            neighboringLives += 1;
                        }
                    }
                    if(neighboringLives < 2){
                        nextState[i][j] = 0;
                    }
                    else if(neighboringLives >= 2 && neighboringLives <= 3){
                        nextState[i][j] = 1;
                    }
                    else{
                        nextState[i][j] = 0;
                    }
                }else{
                    int neighboringLives = 0;
                    for(auto &direction : directions){
                        int ni = i + direction[0];
                        int nj = j + direction[1];
                        if(check(ni,nj,m,n) && board[ni][nj] == 1){
                            neighboringLives += 1;
                        }
                    }
                    if(neighboringLives == 3){
                        nextState[i][j] = 1;
                    }
                }
            }
        }
        board = nextState;
    }
};