class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> result(n+1,INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        for(auto &time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v,w});
        }
        result[k] = 0;
        pq.push({0,k});   //{delay,node}
        while(!pq.empty()){
            pair<int,int> u = pq.top();
            pq.pop();
            int delay = u.first;
            int node  = u.second;
            for(auto &v : adj[node]){
                int vNode  = v.first;
                int vDelay = v.second;
                if(delay+vDelay < result[vNode]){
                    result[vNode] = delay+vDelay;
                    pq.push({result[vNode],vNode});
                }
            }
        }
        int minDelay = 0;
        for(int i=1 ; i<result.size() ; i++){
            minDelay = max(minDelay,result[i]);
        }
        return minDelay == INT_MAX ? -1 : minDelay; 
    }
};