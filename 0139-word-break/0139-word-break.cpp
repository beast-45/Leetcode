class Solution {
public:
    bool solve(int index , int n , string &s , unordered_set<string> &st , vector<int> &dp){
        if(index >= n) return true;
        if(dp[index] != -1){
            return dp[index];
        }
        for(int len=1 ; index+len<=n ; len++){
            string temp = s.substr(index,len);
            if(st.find(temp) != st.end() && solve(index+len,n,s,st,dp)){
                return dp[index] = true;
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> st(begin(wordDict),end(wordDict));
        vector<int> dp(n+1,-1);
        return solve(0,n,s,st,dp);
    }
};
