class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 , minEL = INT_MAX;
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
            minEL = min(minEL,nums[i]);
        }
        return sum - (n*minEL);
    }
};