class Solution {
public:
    typedef pair<double,int> P;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0 ; i<edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<double> result(n,0.0);
        priority_queue<P> pq;
        pq.push({1.0,start_node});
        result[start_node] = 1.0;
        while(!pq.empty()){
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &neighbor : adj[node]){
                int nNode = neighbor.first;
                double probability = neighbor.second;
                double combinedProb = prob*probability;
                if(combinedProb > result[nNode]){
                    result[nNode] = combinedProb;
                    pq.push({result[nNode],nNode});
                }
            }
        }
        return result[end_node];
    }
};