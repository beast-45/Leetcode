class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<bool> lValid(n) , rValid(n);
        lValid[0] = rValid[0] = lValid[n-1] = rValid[n-1] = true;
        int lMax = nums[0] , rMax = nums[n-1];
        for(int i=1 ; i<n-1 ; i++){
            if(nums[i] > lMax) lValid[i] = true;
            lMax = max(lMax,nums[i]);
        }
        for(int i=n-2 ; i>=1 ; i--){
            if(nums[i] > rMax) rValid[i] = true;
            rMax = max(rMax,nums[i]);
        }
        vector<int> result;
        for(int i=0 ; i<n ; i++){
            if(lValid[i] || rValid[i]) result.push_back(nums[i]);
        }
        return result;
    }
};