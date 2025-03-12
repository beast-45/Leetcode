class Solution {
public:
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void unionf(int x , int y , vector<int>&parent , vector<int> &rank){
        int xp = find(x,parent);
        int yp = find(y,parent);
        if(xp == yp){
            return;
        }
        if(rank[xp] > rank[yp]){
            parent[yp] = xp;
        }
        else if(rank[xp] < rank[yp]){
            parent[xp] = yp;
        }
        else{
            parent[xp] = yp;
            rank[yp]++;
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int up = find(u,parent);
            int vp = find(v,parent);
            if(up == vp){
                continue;
            }
            else{
                unionf(u,v,parent,rank);
            }
        }
        return find(source,parent) == find(destination,parent);
    }
};