class Solution {
public:
    bool hasCycle = false;
    void dfs(vector<vector<int>> &adj , int u , vector<bool> &vis , vector<bool> &inRec , vector<int> &result){
        vis[u] = true;
        inRec[u] = true;
        for(int &v : adj[u]){
            if(!vis[v]){
                dfs(adj , v , vis , inRec , result);
            }
            else if(inRec[v]){
                hasCycle = true;
                return;
            }
        }
        inRec[u] = false;
        result.push_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n,false);
        vector<bool> inRec(n,false);
        vector<int> result;
        vector<vector<int>> adj(n);
        for(vector<int> &pre : prerequisites){
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
        }
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                dfs(adj , i , vis , inRec , result);
            }
        }
        if(hasCycle){
            return {};
        }
        else{
            reverse(begin(result),end(result));
        }
        return result;
    }
};