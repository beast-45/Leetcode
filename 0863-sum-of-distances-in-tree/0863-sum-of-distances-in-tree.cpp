class Solution {
public:
    int rootDistance;
    int countDFS(int node , int parentNode , int distance ,  vector<int> &count , vector<vector<int>> &adj){
        int totalCount = 1;
        rootDistance += distance;
        for(int &childNode : adj[node]){
            if(childNode == parentNode) continue;
            totalCount += countDFS(childNode,node,distance+1,count,adj);
        }
        count[node] = totalCount;
        return totalCount;
    }
    void dfs(int node , int parentNode , int n , vector<int> &count , vector<int> &result , vector<vector<int>> &adj){
        for(int &childNode : adj[node]){
            if(childNode == parentNode) continue;
            result[childNode] = result[node] - count[childNode] + (n-count[childNode]);
            dfs(childNode,node,n,count,result,adj);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0);
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        rootDistance = 0;
        countDFS(0,-1,0,count,adj);
        vector<int> result(n,0);
        result[0] = rootDistance;
        dfs(0,-1,n,count,result,adj);
        return result;
    }
};