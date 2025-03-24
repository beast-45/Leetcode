class Solution {
public:
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void unionf(int x , int y , vector<int> &parent){
        int xp = find(x,parent);
        int yp = find(y,parent);
        if(xp == yp){
            return;
        }
        if(xp < yp){
            parent[yp] = xp;
        }
        else if(xp>yp){
            parent[xp] = yp;
        }
        else{
            parent[xp] = yp;
        }
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
        vector<int> parent(26,0);
        for(int i=0 ; i<26 ; i++){
            parent[i] = i;
        }
        for(int i=0 ; i<n ; i++){
            int x = s1[i];
            int y = s2[i];
            int xp = find(x-'a',parent);
            int yp = find(y-'a',parent);
            if(xp != yp){
                unionf(x-'a',y-'a',parent);

            }
        }
        string result = "";
        for(int i=0 ; i<baseStr.size() ; i++){
            result += char(find(baseStr[i]-'a',parent)+'a');
        }
        return result;

    }
};