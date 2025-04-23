class Solution {
public:
    bool check(string &word1 , string &word2){
        int n1 = word1.length();
        int n2 = word2.length();
        if(n1+1 != n2) return false;
        int i = 0 , j = 0 , extraWord = 0;
        while(i<n1 && j<n2){
            if(word1[i] == word2[j]){
                i++;
                j++;
            }
            else{
                extraWord++;
                if(extraWord > 1) return false;
                j++;
            }
        }
        return true;
    }
    int solve(int index , int prevIndex , int n , vector<string> &words , vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        int take = 0;
        if(dp[index][prevIndex+1] != -1){
            return dp[index][prevIndex+1];
        }
        if(prevIndex == -1 || check(words[prevIndex],words[index])){
            take = 1 + solve(index+1,index,n,words,dp);
        }
        int skip = solve(index+1,prevIndex,n,words,dp);
        return dp[index][prevIndex+1] = max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words),end(words),[&](string &w1 , string &w2){
            return w1.length() < w2.length();
        });
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(0,-1,n,words,dp);
    }
};