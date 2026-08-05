class Solution {
public:
    void dfs(int u , vector<int> &indegree , vector<bool> &sus , vector<bool> &vis , vector<vector<int>> &graph){
        vis[u] = true;
        for(int &v : graph[u]){
            indegree[v] -= 1;
            if(!vis[v]){
                sus[v] = true;
                dfs(v,indegree,sus,vis,graph);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> ogGraph;
        for(int i=0 ; i<n ; i++){
            ogGraph.push_back(i);
        }
        vector<int> indegree(n,0);
        for(auto &invocation : invocations){
            adj[invocation[0]].push_back(invocation[1]);
            indegree[invocation[1]] += 1;
        }
        vector<bool> sus(n,false);
        vector<bool> vis(n,false);
        sus[k] = true;
        dfs(k,indegree,sus,vis,adj);
        vector<int> result;
        for(int i=0 ; i<n ; i++){
            if(sus[i] == true){
                if(indegree[i] > 0) return ogGraph;
            }else{
                result.push_back(i);
            }
        }
        return result;
    }
};