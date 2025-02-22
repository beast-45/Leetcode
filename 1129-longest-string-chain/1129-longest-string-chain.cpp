class Solution {
public:
    static bool sortBasedOnLength(const string &word1 , const string &word2){
        return word1.length() < word2.length();
    }

    bool check(string &word1 , string &word2){
        int n1 = word1.length();
        int n2 = word2.length();

        if(n1+1 != n2){
            return false;
        }

        int i = 0; 
        int j = 0;
        int extraWord = 0;

        while(i<n1 && j<n2){
            if(word1[i] == word2[j]){
                i++;
                j++;
            }
            else{
                extraWord += 1;
                if(extraWord > 1){
                    return false;
                }
                j++;
            }
        }
        return true;
    }
    int solve(int index , int prevIndex , vector<string> &words , vector<vector<int>> &dp){
        if(index >= words.size()){
            return 0;
        }

        if(prevIndex != -1 && dp[index][prevIndex] != -1){
            return dp[index][prevIndex];
        }
        int take = 0;
        if(prevIndex == -1 || check(words[prevIndex] , words[index]) == true){
            take = 1 + solve(index+1 , index , words , dp);
        }
        int skip = solve(index+1 , prevIndex , words , dp);

        int ans = max(take , skip);
        if(prevIndex != -1){
            dp[index][prevIndex] = ans;
        }
        return ans;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        sort(begin(words) , end(words) , sortBasedOnLength);
        return solve(0 , -1 , words , dp);
    }
};