class Solution {
public:
    int n;
    int total;
    int t[21][2001];
    int solve(vector<int> &nums , int index , int sum , int target)
    {
        if(index == n)
        {
            if(sum == target) return 1;
            else return 0;
        }

        if(t[index][sum+total] != -1) return t[index][sum+total];

        int plusSign  = solve(nums , index+1 , sum + nums[index] , target);
        int minusSign = solve(nums , index+1 , sum - nums[index] , target);

        return t[index][sum + total] = plusSign + minusSign;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(begin(nums) , end(nums) , 0);
        memset(t , -1 , sizeof(t));
        return solve(nums , 0 , 0 , target);
    }
};