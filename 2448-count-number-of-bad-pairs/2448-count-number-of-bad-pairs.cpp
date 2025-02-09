class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        long long badPairs = 0;
        for(int i=0 ; i<n ; i++){
            nums[i] = nums[i] - i;
        }
        for(int j=0 ; j<n ; j++){
            badPairs += j - mp[nums[j]];
            mp[nums[j]] += 1;
        } 
        return badPairs;
    }
};