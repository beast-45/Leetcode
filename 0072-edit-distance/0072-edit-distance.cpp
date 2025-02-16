class Solution {
public:
    int solve(int i , int j , int m , int n , string &word1 , string &word2 , vector<vector<int>> &mem){
        if(i == m){                  
            return n-j;
        }
        else if(j == n){                   
            return m-i;
        }
        if(mem[i][j] != -1){
            return mem[i][j];
        }
        if(word1[i] == word2[j]){
            return mem[i][j] = solve(i+1 , j+1 , m , n , word1 , word2 , mem);
        }
        else{
            int insert = 1 + solve(i , j+1 , m , n , word1 , word2 , mem);
            int del = 1 + solve(i+1 , j , m , n , word1 , word2 , mem);
            int replace = 1 + solve(i+1 , j+1 , m , n , word1 , word2 , mem);
            return mem[i][j] = min({insert , del , replace});
        }
        return -1;
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> mem(m , vector<int>(n,-1));
        return solve(0 , 0 , m , n , word1 , word2 , mem);
    }
};