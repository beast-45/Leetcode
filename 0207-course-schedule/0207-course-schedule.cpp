class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses , count = 0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
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
        return count == n ? true : false;
    }
};