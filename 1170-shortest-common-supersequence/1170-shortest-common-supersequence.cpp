class Solution {
public:
    vector<vector<int>> dp;
    int findLength(string &s1, string &s2, int i, int j) {
        if (i == s1.length()){
            return s2.length() - j; 
        }
        if (j == s2.length()){
            return s1.length() - i; 
        }

        if (dp[i][j] != -1){
            return dp[i][j];
        }

        if (s1[i] == s2[j]){
            return dp[i][j] = 1 + findLength(s1, s2, i + 1, j + 1);
        }
        return dp[i][j] = 1 + min(findLength(s1, s2, i + 1, j), findLength(s1, s2, i, j + 1));
    }

    string buildSupersequence(string &s1, string &s2) {
        string result;
        int i = 0, j = 0;

        while (i < s1.length() && j < s2.length()) {
            if (s1[i] == s2[j]) {
                result.push_back(s1[i]);
                i++, j++;
            } 
            else if (dp[i + 1][j] == -1 || (dp[i][j + 1] != -1 && dp[i][j + 1] < dp[i + 1][j])) {
                result.push_back(s2[j]);
                j++;
            } 
            else {
                result.push_back(s1[i]);
                i++;
            }
        }
        while (i < s1.length()){
            result.push_back(s1[i++]);
        }
        while (j < s2.length()){
            result.push_back(s2[j++]);
        }

        return result;
    }

    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        findLength(s1, s2, 0, 0);  
        return buildSupersequence(s1, s2);  
    }
};
