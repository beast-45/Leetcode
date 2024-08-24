class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int csum = 0;
        for(int i=0 ; i<n ; i++)
        {
            csum += nums[i];
            result.push_back(csum);
        }
        return result;
        
    }
};