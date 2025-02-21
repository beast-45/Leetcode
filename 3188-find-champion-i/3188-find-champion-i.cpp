class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int champ = 0;
        int max1Count = 0;

        for(int i=0 ; i<m ; i++){
            int count1 = count(grid[i].begin() , grid[i].end() , 1);
            if(count1 > max1Count){
                champ = i;
                max1Count = count1;
            }
        }
        return champ; 
    }
};