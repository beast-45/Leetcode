class Solution {
public:
    typedef pair<long long,int> P;
    int m = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> result(n,LLONG_MAX);
        vector<vector<P>> adj(n);
        vector<int> ways(n,0);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<P,vector<P>,greater<P>> pq;

        pq.push({0,0});
        result[0] = 0;
        ways[0] = 1;

        while(!pq.empty()){
            long long t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &neighbor : adj[node]){
                int nNode = neighbor.first;
                long long time = neighbor.second;
                if(t+time < result[nNode]){
                    result[nNode]= t + time;
                    pq.push({result[nNode],nNode});
                    ways[nNode] = ways[node];
                }
                else if(t+time == result[nNode]){
                    ways[nNode] =(ways[nNode] + ways[node])%m;
                }
            }
        }
        return ways[n-1];
    }
};