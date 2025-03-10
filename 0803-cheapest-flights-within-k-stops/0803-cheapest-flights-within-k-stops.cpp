class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto& flight : flights){
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back({v,w});
        }
        int count = 0; 
        queue<pair<int,int>> q;
        q.push({src,0});
        result[src] = 0;
        while(!q.empty() && count <= k){
            int s = q.size();
            while(s--){
                auto t = q.front();
                q.pop();
                int u = t.first;
                int w = t.second;
                for(auto &v : adj[u]){
                    int nv = v.first;
                    int nw = v.second;
                    if(w+nw < result[nv]){
                        result[nv] = w+nw;
                        q.push({nv,result[nv]});
                    }
                }
            }
            count += 1;
        }
        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};