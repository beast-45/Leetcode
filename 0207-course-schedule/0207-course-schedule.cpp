class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n,0);
        queue<int> q;
        int count = 0;
        unordered_map<int,vector<int>> adj;
        for(auto &u : prerequisites){
            int a = u[0];
            int b = u[1];
            adj[b].push_back(a);
            indegree[a] += 1;
        }

        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
                count += 1;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count += 1;
                }
            }
        }
        return count == n;
    }
};