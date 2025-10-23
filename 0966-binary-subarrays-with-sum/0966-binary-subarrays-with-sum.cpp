class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size() , cs = 0 , count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0 ; i<n ; i++){
            cs += nums[i];
            int rem = cs-goal;
            if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[cs] += 1;
        }
        return count;
    }
};