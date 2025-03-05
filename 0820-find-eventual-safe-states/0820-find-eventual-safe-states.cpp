class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> indegree(n,0);
        queue<int> q;
        vector<vector<int>> adj(n);
        vector<int> result;

        for(int u=0 ; u<n ; u++){
            for(int &v  : graph[u]){
                adj[v].push_back(u);    //u--->v => v--->u
                indegree[u]+=1;
            }
        }
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            result.push_back(u);
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        sort(begin(result),end(result));
        return result;
    }
};