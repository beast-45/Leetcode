class Solution {
public:
    void dfs(int u , vector<bool> &vis , vector<bool> &inrec , vector<int> &count , vector<int> &edges , int &lc){
        vis[u] = true;
        inrec[u] = true;
        int v = edges[u];
        if(v != -1){
            if(!vis[v]){
                count[v] = count[u] + 1;
                dfs(v,vis,inrec,count,edges,lc);
            }
            else if(inrec[v]){ 
                int cycle = count[u] - count[v] + 1;
                lc = max(lc,cycle);
            }
        }
        inrec[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> count(n,0);
        vector<bool> vis(n,false) , inrec(n,false);
        int longestCycle = -1;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,vis,inrec,count,edges,longestCycle);
            }
        }
        return longestCycle;
    }
};