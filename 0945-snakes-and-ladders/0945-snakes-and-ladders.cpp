class Solution {
public:
    pair<int,int> getCoordinates(int x , int n){
        int num = x-1;
        int row = num/n;
        int actualRow = (n-1)-row;
        int col = num%n;
        int actualCol = -1;
        if(n%2 == 0 && actualRow%2 == 0 || n%2 == 1 && actualRow%2 == 1){
            actualCol = (n-1)-col;
        }else{
            actualCol = col;
        }
        return {actualRow,actualCol};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<int> q;
        q.push(1);
        vis[n-1][0] = true;
        int steps = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int current = q.front();
                q.pop();
                if(current == n*n) return steps;
                for(int i=1 ; i<=6 ; i++){
                    int next = current + i;
                    if(next > n*n) break;
                    auto coordinates = getCoordinates(next,n);
                    auto [r,c] = coordinates;
                    if(!vis[r][c]){
                        if(board[r][c] == -1) q.push(next);
                        else q.push(board[r][c]);
                    }
                    vis[r][c] = true;
                }
            }
            steps++;
        }
        return -1;
    }
};