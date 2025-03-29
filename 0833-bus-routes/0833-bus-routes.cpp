class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        unordered_map<int,vector<int>> adj;
        int n = routes.size();
        for(int i=0 ; i<n ; i++){
            for(int &stop : routes[i]){
                adj[stop].push_back(i);
            }
        }
        vector<bool> vis(n,false);
        queue<int> q;
        for(int &route : adj[source]){
            q.push(route);
            vis[route] = true;
        }
        int buses = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                int route = q.front();
                q.pop();
                for(int &stop : routes[route]){
                    if(stop ==  target){
                        return buses;
                    }
                    for(int &nextRoute : adj[stop]){
                        if(!vis[nextRoute]){
                            q.push(nextRoute);
                            vis[nextRoute] = true;
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};