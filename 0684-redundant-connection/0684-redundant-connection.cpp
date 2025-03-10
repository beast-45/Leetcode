class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }
    void unionf(int x, int y, vector<int>& parent, vector<int>& rank) {
        int xp = find(x, parent);
        int yp = find(y, parent);

        if (xp == yp) {
            return;
        }
        if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else {
            parent[xp] = yp;
            rank[yp] += 1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1,0);
        for(int i=1 ; i<n+1 ; i++){
            parent[i] = i;
        }
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            int up = find(u,parent);
            int vp = find(v,parent);

            if(up != vp){
                unionf(u,v,parent,rank);
            }
            else{
                return {u,v};
            }
        }
        return {-1,-1};
    }
};