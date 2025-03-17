class Solution {
public:
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i , int j , int m , int n , vector<vector<char>> &board){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '.'){
            return;
        }
        board[i][j] = '.';
        for(auto & direction : directions){
            int ni = i + direction[0];
            int nj = j + direction[1];
            dfs(ni , nj , m , n , board);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int count = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == 'X'){
                    dfs(i , j , m , n , board);
                    count += 1;
                }
            }
        }
        return count;
    }
};