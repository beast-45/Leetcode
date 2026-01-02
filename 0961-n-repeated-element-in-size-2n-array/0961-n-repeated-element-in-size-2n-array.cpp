class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &num : nums){
            mp[num]++;
            if(mp[num] > 1) return num;
        } 
        return -1;
    }
};