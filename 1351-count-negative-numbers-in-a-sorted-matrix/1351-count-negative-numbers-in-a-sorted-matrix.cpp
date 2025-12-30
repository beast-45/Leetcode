class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid[0].size() , count = 0;
        for(auto &row : grid){
            int index = upper_bound(begin(row),end(row),0,greater<int>()) - begin(row);
            int num = n - index;
            count += num;
        }
        return count;
    }
};