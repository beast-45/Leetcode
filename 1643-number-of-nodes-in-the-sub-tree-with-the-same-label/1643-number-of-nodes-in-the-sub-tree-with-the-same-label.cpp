class Solution {
public:
    vector<int> dfs(vector<vector<int>> &adj , int currentNode , int parent , vector<int> &result , string &labels){
        vector<int> count(26,0);
        char label = labels[currentNode];
        count[label-'a'] = 1;
        for(int &child : adj[currentNode]){
            if(child == parent){
                continue;
            }
            vector<int> childCount(26,0);
            childCount = dfs(adj,child,currentNode,result,labels);
            for(int i=0 ; i<26 ; i++){
                count[i] += childCount[i];
            }
        }
        result[currentNode] = count[label-'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> result(n,0);
        dfs(adj , 0 , -1 , result , labels);
        return result;
    }
};