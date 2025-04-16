class Solution {
public:
    bool solve(int index , int n , string &s , unordered_set<string> &wDict , vector<int> &dp){
        if(index >= n){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        for(int len=1 ; len<=n ; len++){
            string temp = s.substr(index,len);
            if(wDict.find(temp) != wDict.end() && solve(index+len,n,s,wDict,dp)){
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) { 
        int n = s.length();
        vector<int> dp(n+1,-1);
        unordered_set<string> wDict(begin(wordDict),end(wordDict));
        return solve(0,n,s,wDict,dp);
    }
};