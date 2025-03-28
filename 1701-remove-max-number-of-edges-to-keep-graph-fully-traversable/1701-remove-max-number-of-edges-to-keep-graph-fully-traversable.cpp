class DSU{
    public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n){
        parent.resize(n+1);
        for(int i=1 ; i<=n ; i++){
            parent[i] = i;
        }
        rank.resize(n+1);
        components = n;
    }

    int find(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void unionf(int x , int y){
        int xp = find(x);
        int yp = find(y);
        if(xp==yp){
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
        components--;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        sort(begin(edges),end(edges),[](auto &e1 , auto &e2){
            return e1[0]>e2[0];
        });
        int edgesDrawn = 0;
        for(auto &edge : edges){
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type == 3){
                bool edgeDrawn = false;
                if(alice.find(u) != alice.find(v)){
                    alice.unionf(u,v);
                    edgeDrawn = true;
                }
                if(bob.find(u) != bob.find(v)){
                    bob.unionf(u,v);
                    edgeDrawn = true;
                }
                if(edgeDrawn){
                    edgesDrawn++;
                }
            }
            else if(type == 2){
                if(bob.find(u) != bob.find(v)){
                    bob.unionf(u,v);
                    edgesDrawn++;
                }
            }
            else{
                if(alice.find(u) != alice.find(v)){
                    alice.unionf(u,v);
                    edgesDrawn++;
                }
            }
        }
        if(alice.components == 1 && bob.components==1){
            return edges.size()-edgesDrawn;
        }
        return -1;  
    }
};