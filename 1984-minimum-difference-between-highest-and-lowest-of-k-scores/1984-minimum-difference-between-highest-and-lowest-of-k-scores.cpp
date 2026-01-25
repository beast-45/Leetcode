class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // if(k >= nums.size()) return 0;
        sort(begin(nums),end(nums));
        int i = 0 , j = k-1 , maxScore = INT_MAX;
        while(j < nums.size()){
            maxScore = min(maxScore,nums[j]-nums[i]);
            j++;
            i++;
        }
        return maxScore;
    }
};