class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                nums.push_back(grid[i][j]);
            }
        }
        sort(begin(nums),end(nums));
        int count = 0;
        int total = m*n;
        int target = nums[total/2];
        for(int &num : nums){
            if(num%x != target%x){
                return -1;
            }
            count += abs(target-num)/x;
        }
        return count;
    }
};