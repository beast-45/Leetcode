class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size() , cs = 0 , count = 0;
        for(int i=0 ; i<n ; i++){
            cs += nums[i];
            int rem = cs - k;
            if(mp.find(rem) != mp.end()) count += mp[rem];
            mp[cs] += 1;
        }
        return count;
        
    }
};