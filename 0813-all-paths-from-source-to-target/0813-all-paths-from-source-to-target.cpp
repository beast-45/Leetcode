class Solution {
public:
    void dfs(vector<vector<int>>&graph , int u , int destination , vector<int> &path , vector<vector<int>> &result){
        if(u == destination){
            result.push_back(path);
            return;
        }
        for(int &v : graph[u]){
            path.push_back(v);
            dfs(graph , v , destination , path , result);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> path;
        vector<vector<int>> result;
        path.push_back(0);
        dfs(graph, 0 , n-1 , path , result);
        return result;
    }
};