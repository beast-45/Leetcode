class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        queue<int> q;
        vector<int> indegree(n,0);
        int count = 0;
        vector<vector<int>> adj(n);
        for(auto &prerequisite : prerequisites){
            int a = prerequisite[0];
            int b = prerequisite[1];
            adj[b].push_back(a);
            indegree[a]+=1;
        }
        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
                count+=1;
            }
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                indegree[v]-=1;
                if(indegree[v] == 0){
                    q.push(v);
                    count+=1;
                }
            }
        }
        return count == n ? true : false;
    }
};