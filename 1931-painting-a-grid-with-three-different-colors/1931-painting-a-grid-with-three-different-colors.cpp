class Solution {
public:
    int M = 1e9+7;
    vector<char> colors{'R','G','B'};
    vector<string> columnStates;
    void generateColumnStates(string curr , char prevColor , int l , int m){
        if(l == m){
            columnStates.push_back(curr);
            return;
        }
        for(char color : colors){
            if(color == prevColor) continue;
            generateColumnStates(curr+color,color,l+1,m);
        }
    }
    int solve(int prevStateIndex , int remCols , vector<vector<int>> &dp){
        if(remCols == 0) return 1;
        if(dp[remCols][prevStateIndex] != -1) return dp[remCols][prevStateIndex];
        int ways = 0;
        string prevState = columnStates[prevStateIndex];
        for(int i=0 ; i<columnStates.size() ; i++){
            if(i == prevStateIndex) continue;
            string currState = columnStates[i];
            bool valid = true;
            for(int j=0 ; j<currState.size() ; j++){
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(i,remCols-1,dp)) % M;
            }
        }
        return dp[remCols][prevStateIndex] = ways;
    }
    int colorTheGrid(int m, int n) {
        generateColumnStates("",'*',0,m);
        int result = 0;
        vector<vector<int>> dp(n+1,vector<int>(columnStates.size()+1,-1));
        for(int i=0 ; i<columnStates.size() ; i++){
            result = (result + solve(i,n-1,dp)) % M;
        }
        return result;
    }
};