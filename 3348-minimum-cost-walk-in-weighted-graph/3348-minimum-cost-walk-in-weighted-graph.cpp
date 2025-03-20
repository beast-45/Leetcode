class Solution {
public:
    typedef pair<int,int> P;
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void unionf(int x , int y , vector<int> &parent){
        parent[y] = x;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> parent(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        vector<int> parentAND(n,-1);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            int up = find(u,parent);
            int vp = find(v,parent);
            if(up != vp){
                unionf(up,vp,parent);
                parentAND[up] &= parentAND[vp];
            }
            parentAND[up] &= w;
        }
        vector<int> result;
        for(auto &q : query){
            int u = q[0];
            int v = q[1];
            int up = find(u,parent);
            int vp = find(v,parent);
            if(u == v){
                result.push_back(0);
            }
            else if(up != vp){
                result.push_back(-1);
            }
            else{
                result.push_back(parentAND[up]);
            }
        }
        return result;
    }
};