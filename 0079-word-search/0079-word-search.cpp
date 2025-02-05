class Solution {
public: 
    bool search(vector<vector<char>> &board , int i , int j , int index , string &word , vector<vector<int>>&directions){
        if(index == word.length()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] == '$'){
            return false;
        }
        if(board[i][j] != word[index]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(search(board , new_i , new_j , index+1 , word , directions)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(board[i][j] == word[0] && search(board , i , j , 0 , word , directions)){
                    return true;
                }
            }

        }
        return false;
    }
};