class Solution {
public:
    void dfs(vector<int> &edges , int node , vector<int> &result , vector<bool> &vis){
        vis[node] = true;
        int nextNode = edges[node];
        if(nextNode != -1 && !vis[nextNode]){
            result[nextNode] = result[node]+1;
            dfs(edges,nextNode,result,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<bool> vis1(n,false);
        vector<int> result1(n,INT_MAX);
        result1[node1] = 0;

        vector<bool> vis2(n,false);
        vector<int> result2(n,INT_MAX);
        result2[node2] = 0;

        dfs(edges,node1,result1,vis1);
        dfs(edges,node2,result2,vis2);

        int minDistNode = -1;
        int minDistanceTillNow = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int maxDistance = max(result1[i],result2[i]);
            if(maxDistance < minDistanceTillNow){
                minDistanceTillNow = maxDistance;
                minDistNode = i;
            }
        }
        return minDistNode;
        
    }
};