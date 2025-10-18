class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionf(int x , int y){
        int xp = find(x);
        int yp = find(y);
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        int provinces = n;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    int ip = dsu.find(i);
                    int jp = dsu.find(j);
                    if(ip != jp){
                        dsu.unionf(i,j);
                        provinces--;
                    }
                }
            }
        }
        return provinces;
    }
};