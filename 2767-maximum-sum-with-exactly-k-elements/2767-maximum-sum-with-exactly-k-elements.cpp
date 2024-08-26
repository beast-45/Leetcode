class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int sum = 0;
        int maxi = nums[n-1];
        for(int i=0 ; i<k ; i++)
        {
            sum+=maxi;
            maxi+=1;
        }
        return sum;
        
    }
};