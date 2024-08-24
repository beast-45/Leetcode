class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        sort(nums.begin() , nums.end());
        for(int i=1 ; i<n ; i+=2)
        {
            result.push_back(nums[i]);
            result.push_back(nums[i-1]);
        }
        return result;
        
    }
};