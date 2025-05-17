class DSU{
    public:
    vector<int> parent , rank;
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unionByRank(int x , int y){
        int xp = find(x) , yp = find(y);
        if(xp == yp) return;
        if(rank[xp] > rank[yp]) parent[yp] = xp;
        else if(rank[xp] < rank[yp]) parent[xp] = yp;
        else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto &edge : edges){
            int u = edge[0] , v = edge[1];
            int up = dsu.find(u) , vp = dsu.find(v);
            if(up != vp){
                dsu.unionByRank(u,v);
            }
            else{
                return {u,v};
            }
        }
        return {-1,-1};
    }
};