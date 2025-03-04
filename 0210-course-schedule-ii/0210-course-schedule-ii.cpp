class Solution {
public:

    // Using kahn's Algorithm (BFS)
    void bfs(unordered_map<int,vector<int>> &adj , vector<int> &indegree , vector<int> &result , int n , int &count){
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
            for(int &v : adj[u]){
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
        unordered_map<int,vector<int>> adj;
        vector<int> result;
        vector<int> indegree(n,0);
        int count = 0;
        for(auto &pre : prerequisites){
            int a = pre[0];
            int b = pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        bfs(adj , indegree , result , n , count);
        return count != n ? vector<int>{} : result; 
    }
};

//Using DFS
class Solution {
public:
    bool hasCycle = false;
    void dfs(unordered_map<int,vector<int>> &adj , int u , vector<bool> &vis , vector<bool> &inRec , vector<int> &result){
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

        unordered_map<int,vector<int>> adj;
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
