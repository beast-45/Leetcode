class Solution {
public:
    int solve(int idx , int currOR , vector<int> &nums , int maxOR)
    {
        if(idx ==  nums.size())
        {
            if(currOR == maxOR) return 1;
            return 0;
        }

        int take    = solve(idx+1 , currOR | nums[idx] , nums , maxOR);
        int notTake = solve(idx+1 , currOR , nums , maxOR);

        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int &num : nums)
        {
            maxOR |= num;
        }
        int currOR = 0;
        return solve(0 , currOR , nums , maxOR);   
    }
};