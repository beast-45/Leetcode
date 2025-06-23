class Solution {
public:
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x],parent);
    }
    void unionf(int x , int y , vector<int> &parent , vector<int> &rank){
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n,0) , parent(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        int provinces = n;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    int ip = find(i,parent);
                    int jp = find(j,parent);
                    if(ip != jp){
                        unionf(i,j,parent,rank);
                        provinces--;
                    }
                }
            }
        }
        return provinces;
        
    }
};