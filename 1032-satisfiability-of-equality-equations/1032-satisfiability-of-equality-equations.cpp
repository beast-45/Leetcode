class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unionf(int x , int y){
        int xp = find(x);
        int yp = find(y);
        if(xp == yp) return false;
        if(rank[xp] > rank[yp]) parent[yp] = xp;
        else if(rank[xp] < rank[yp]) parent[xp] = yp;
        else{
            parent[xp] = yp;
            rank[yp]++;
        }
        return true;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(auto &eq : equations){
            if(eq[1] == '='){
                dsu.unionf(eq[0]-'a',eq[3]-'a');
            }
        }
        for(auto &eq : equations){
            if(eq[1] == '!'){
                if(dsu.find(eq[0]-'a') == dsu.find(eq[3]-'a')) return false;
            }
        }
        return true;
    }
};