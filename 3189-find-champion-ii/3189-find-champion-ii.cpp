class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> power(n);
        int countZ = 0;
        for(vector<int> &edge : edges)
        {
            int incoming = edge[1];
            power[edge[1]] += 1;
        }
        for(int i=0 ; i<n ; i++)
        {
            if(power[i]==0) countZ++;
        }
        int idxZ = 0;
        if(countZ == 1)
        {
            for( ; idxZ<n ; idxZ++)
            {
                if(power[idxZ] == 0) break;
            }
        }
        return countZ==1 ? idxZ : -1;
        
    }
};