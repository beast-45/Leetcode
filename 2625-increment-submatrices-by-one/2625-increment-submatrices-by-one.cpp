class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n,vector<int>(n,0));
        for(auto &query : queries){
            int r1 = query[0] , r2 = query[2];
            int c1 = query[1] , c2 = query[3];
            for(int i=r1 ; i<=r2 ; i++){
                result[i][c1] += 1;
                if(c2+1 < n) result[i][c2+1] -= 1;
            }      
        }
        for(auto &res : result){
            int sum = 0;
            for(int i=0 ; i<n ; i++){
                sum += res[i];
                res[i] = sum;
            }
        }
        return result;
    }
};