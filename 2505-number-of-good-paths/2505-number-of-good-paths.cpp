class Solution {
public:
    vector<int> parent;
    vector<int> rank;
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
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        unordered_map<int,vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> valToNodes;
        for(int i=0 ; i<n ; i++){
            int val = vals[i];
            valToNodes[val].push_back(i);
        }
        int result = n;
        vector<bool> isActive(n,false);
        for(auto &it : valToNodes){
            vector<int> nodes = it.second;
            for(int &u : nodes){
                for(int &v : adj[u]){
                    if(isActive[v]){
                        unionf(u,v);
                    }
                }
                isActive[u] = true;
            }
            vector<int> nodeParents;
            for(int &u : nodes){
                int up = find(u);
                nodeParents.push_back(up);
            }
            sort(begin(nodeParents),end(nodeParents));
            int sz = nodeParents.size();
            for(int j=0 ; j<sz ; j++){
                int count = 0;
                int currentParent = nodeParents[j];
                while(j<sz && nodeParents[j]==currentParent){
                    count++;
                    j++;
                }
                j--;
                int paths = (count*(count-1)/2);
                result += paths;
            }
        }
        return result;
    }
};