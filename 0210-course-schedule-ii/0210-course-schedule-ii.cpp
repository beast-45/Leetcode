class Solution {
public:
    void kahnAlgo(int n , int &count , vector<int> &indegree , vector<int> &result , vector<vector<int>> &adj){
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
            result.push_back(u);
            for(auto &v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count += 1;
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> indegree(n) , result;
        vector<vector<int>> adj(n);
        for(auto &pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        int count = 0;
        kahnAlgo(n,count,indegree,result,adj);
        return count == n ? result : vector<int>{};
    }
};
