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

        vector<bool> vis(n,false);
        vector<int> result1(n,INT_MAX);
        result1[node1] = 0;
        dfs(edges,node1,result1,vis);

        fill(begin(vis),end(vis),false);
        vector<int> result2(n,INT_MAX);
        result2[node2] = 0;
        dfs(edges,node2,result2,vis);

        int node = -1;
        int minDist = INT_MAX;

        for(int i=0 ; i<n ; i++){
            int maxDist = max(result1[i],result2[i]);
            if(maxDist < minDist){
                minDist = maxDist;
                node = i;
            }
        }
        return node;  
    }
};