class Solution {
public:
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x] , parent);
    }
    void unionf(int x , int y , vector<int> &parent , vector<int> &rank){
        int x_parent = find(x , parent);
        int y_parent = find(y , parent);

        if(x_parent == y_parent){
            return;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n-1){
            return -1;
        }
        vector<int> parent(n);
        vector<int> rank(n,0);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        int components = n;
        for(auto &connection : connections){
            int x = connection[0];
            int y = connection[1];

            int x_parent = find(x,parent);
            int y_parent = find(y,parent); 

            if(x_parent == y_parent){
                continue;
            }
            else{
                unionf(x , y , parent , rank);
                components--;
            }
        }
        return components-1;
    }
};