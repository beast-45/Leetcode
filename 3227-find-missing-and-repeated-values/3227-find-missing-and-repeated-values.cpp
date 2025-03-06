class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> mp;
        vector<int> result(2);
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                mp[grid[i][j]] += 1;
            }
        }
        
        for(int i=1 ; i<=n*n ; i++){
            if(mp.find(i) == mp.end()){
                result[1] = i;
            }
            else if(mp[i] == 2){
                result[0] = i;
            }
        }
        return result;
        
    }
};