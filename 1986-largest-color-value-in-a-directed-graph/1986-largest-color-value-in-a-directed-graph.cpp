class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size() , countNodes = 0 , result = 0;
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>> dp(n,vector<int>(26,0));
        queue<int> q;
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i);
                countNodes++;
            }
        }
        while(!q.empty()){
            int currentNode = q.front();
            q.pop();
            int color = colors[currentNode]-'a';
            dp[currentNode][color]++;
            result = max(result,dp[currentNode][color]);
            for(int &nextNode : adj[currentNode]){
                indegree[nextNode]--;
                if(indegree[nextNode] == 0){
                    q.push(nextNode);
                    countNodes++;
                }
                for(int i=0 ; i<26 ; i++){
                    dp[nextNode][i] = max(dp[nextNode][i],dp[currentNode][i]);
                }
            }
        }
        return countNodes == n ? result : -1;
    }
};