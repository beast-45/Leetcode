class Solution {
public:
    int M = 1e9+7;
    vector<char> colors{'R','G','B'};
    vector<string> rowStates;
    void generateRowStates(string curr , char prevColor , int length){
        if(length == 3){
            rowStates.push_back(curr);
            return;
        }
        for(char color : colors){
            if(color == prevColor) continue;
            generateRowStates(curr+color,color,length+1);
        }
    }
    int solve(int remRows , int prevStateIndex , vector<vector<int>> &dp){
        if(remRows == 0) return 1;
        if(dp[remRows][prevStateIndex] != -1) return dp[remRows][prevStateIndex];
        int ways = 0;
        string prevState = rowStates[prevStateIndex];
        for(int i=0 ; i<rowStates.size() ; i++){
            if(i == prevStateIndex) continue;
            string currState = rowStates[i];
            bool valid = true;
            for(int j=0 ; j<currState.size() ; j++){
                if(prevState[j] == currState[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ways = (ways + solve(remRows-1,i,dp)) % M;
            }
        }
        return dp[remRows][prevStateIndex] = ways;
    }
    int numOfWays(int n) {
        generateRowStates("",'*',0);
        int result = 0;
        vector<vector<int>> dp(n+1,vector<int>(rowStates.size()+1,-1));
        for(int i=0 ; i<rowStates.size() ; i++){
            result = (result + solve(n-1,i,dp)) % M;
        }
        return result;
    }
};