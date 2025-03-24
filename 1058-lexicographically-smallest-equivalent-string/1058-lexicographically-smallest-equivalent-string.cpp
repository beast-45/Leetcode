class Solution {
public:
    char dfs(unordered_map<char,vector<char>> &adj , int uChar , vector<bool> &vis){
        vis[uChar-'a'] = true;
        char minChar = uChar;
        for(char &vChar : adj[uChar]){
            if(!vis[vChar-'a']){
                minChar = min(minChar,dfs(adj,vChar,vis));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        vector<bool> vis(26,false);
        unordered_map<char,vector<char>> adj;
        for(int i=0 ; i<n ; i++){
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result = "";
        for(int i=0 ; i<baseStr.size() ; i++){
            vis.assign(26,false);
            result += dfs(adj , baseStr[i] , vis);
        }
        return result;
    }
};