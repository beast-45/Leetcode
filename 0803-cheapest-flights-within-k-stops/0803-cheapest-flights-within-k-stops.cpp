class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> result(n,INT_MAX);
        result[src] = 0;
        for(int i=0 ; i<=k ; i++){
            vector<int> temp = result;
            for(auto &flight : flights){
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if(result[u] != INT_MAX && result[u] + w < temp[v]){
                    temp[v] = result[u] + w;
                }
            }
            result = temp;
        }
        return result[dst] == INT_MAX ? -1 : result[dst];
    }
};