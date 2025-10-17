class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> result(n+1,INT_MAX);
        vector<vector<P>> adj(n+1);
        for(auto &time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        result[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [delay,node] = pq.top();
            pq.pop();
            for(auto &[nNode,nDelay] : adj[node]){
                if(delay + nDelay < result[nNode]){
                    result[nNode] = delay + nDelay;
                    pq.push({result[nNode],nNode});
                }
            }
        }
        int minDelay = *max_element(begin(result)+1,end(result));
        return minDelay == INT_MAX ? -1 : minDelay;
    }
};