class Solution {
public:
    void dfs(int node , vector<int> &result , vector<int> &edges, vector<bool> &vis){
        vis[node] = true;
        int nextNode = edges[node];
        if(nextNode != -1 && !vis[nextNode]){
            result[nextNode] = result[node]+1;
            dfs(nextNode,result,edges,vis);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<bool> vis(n,false);
        vector<int> result1(n,INT_MAX) , result2(n,INT_MAX);
        result1[node1] = 0;
        result2[node2] = 0;
        dfs(node1,result1,edges,vis);
        vis.assign(n,false);
        dfs(node2,result2,edges,vis);

        int node = -1 , minDist = INT_MAX;
        for(int i=0 ; i<n ; i++){
            int maxDist = max(result1[i],result2[i]);
            if(maxDist < minDist){
                node = i;
                minDist = maxDist;
            }
        }
        return node;
    }
};