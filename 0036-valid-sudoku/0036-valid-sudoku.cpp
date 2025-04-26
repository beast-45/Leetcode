class Solution {
public:
    bool check(int sr , int er , int sc , int ec , vector<vector<char>> &grid){
        unordered_set<char> st;
        for(int i=sr ; i<=er ; i++){
            for(int j=sc ; j<=ec ; j++){
                char ch = grid[i][j];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0 ; r<9 ; r++){
            unordered_set<char> st;
            for(int c=0 ; c<9 ; c++){
                char ch = board[r][c];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        for(int c=0 ; c<9 ; c++){
            unordered_set<char> st;
            for(int r=0 ; r<9 ; r++){
                char ch = board[r][c];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        for(int sr=0 ; sr<9 ; sr+=3){
            int er = sr + 2;
            for(int sc=0 ; sc<9 ; sc+=3){
                int ec = sc + 2;
                if(!check(sr,er,sc,ec,board)) return false;
            }
        }
        return true;
    }
};