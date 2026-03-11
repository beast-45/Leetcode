class Solution {
public:
    void dfs(int u , vector<bool> &vis , vector<bool> &inRec , vector<int> &count , vector<int> &edges , int &lc){
        vis[u] = true;
        inRec[u] = true;
        int v = edges[u];
        if(v != -1){
            if(!vis[v]){
                count[v] = count[u] + 1;
                dfs(v,vis,inRec,count,edges,lc);
            }else if(inRec[v]){
                int cycleLength = count[u]-count[v]+1;
                lc = max(lc,cycleLength);
            }
        }
        inRec[u] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size() , longest = -1;
        vector<int> count(n,0);
        vector<bool> vis(n,false) , inRec(n,false);
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,vis,inRec,count,edges,longest);
            }
        }
        return longest;
    }
};