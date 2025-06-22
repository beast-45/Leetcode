class Solution {
public:
    int find(int x , vector<int> &parent){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find(parent[x] , parent);
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
            rank[yp] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> rank(26,0);
        vector<int> parent(26);
        for(int i=0 ; i<26 ; i++){
            parent[i] = i;
        }
        for(string &equation : equations){
            if(equation[1] == '='){
                unionf(equation[0]-'a' , equation[3]-'a' , parent , rank);
            }
        }
        for(string &equation : equations){
            if(equation[1] == '!'){
                char x = equation[0] , y = equation[3];
                int x_parent = find(x-'a',parent);
                int y_parent = find(y-'a',parent);
                if(x_parent == y_parent){
                    return false;
                }
            }
        }
        return true; 
    }
};