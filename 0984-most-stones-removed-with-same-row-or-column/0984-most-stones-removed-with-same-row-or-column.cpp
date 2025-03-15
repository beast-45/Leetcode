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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> rank(n,0);
        vector<int> parent(n);
        for(int i=0 ; i<n ; i++){
            parent[i] = i;
        }
        int groups = n;
        for(int i=0 ; i<n-1 ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    if(find(i,parent) != find(j,parent)){
                        unionf(i,j,parent,rank);
                        groups--;
                    }
                }
            }
        }
        return n-groups; 
    }
};