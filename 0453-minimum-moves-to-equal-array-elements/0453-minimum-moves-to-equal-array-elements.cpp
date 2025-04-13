class Solution {
public:
    int minMoves(vector<int>& nums) {
        int moves = 0;
        int minVal = *min_element(begin(nums),end(nums));
        for(int &num : nums){
            moves += num-minVal;
        }
        return moves;
    }
};