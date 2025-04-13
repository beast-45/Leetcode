class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int apt = nums[n/2];
        int moves = 0;
        for(int &num : nums){
            moves += abs(num-apt);
        }
        return moves;
    }
};