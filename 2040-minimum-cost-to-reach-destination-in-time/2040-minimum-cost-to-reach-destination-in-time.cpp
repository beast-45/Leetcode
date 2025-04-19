class Solution {
public:
    typedef pair<int,int> P;
    int solve(int start , int end , vector<vector<P>> &adj , vector<int> &passingFees , int time , int maxTime ,  vector<vector<int>> &dp){
        if(time > maxTime){
            return INT_MAX;
        }
        if(start == end){
            return passingFees[end];
        }
        if(dp[start][time] != -1){
            return dp[start][time];
        }
        int minCost = INT_MAX;
        int cost = passingFees[start];
        for(auto &neighbor : adj[start]){
            int v = neighbor.first;
            int t = neighbor.second;
            int vCost = solve(v,end,adj,passingFees,time+t,maxTime,dp);
            if(vCost != INT_MAX){
                minCost = min(minCost,cost+vCost);
            }
        }
        return dp[start][time] = minCost;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<P>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<vector<int>> dp(n+1,vector<int>(maxTime+1,-1));
        int result = solve(0,n-1,adj,passingFees,0,maxTime,dp);
        return result == INT_MAX ? -1 : result; 
    }
};