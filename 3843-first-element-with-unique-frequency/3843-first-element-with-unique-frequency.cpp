class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &num : nums){
            mp[num] += 1;
        }
        unordered_map<int,int> freqCount;
        for(auto &it : mp){
            freqCount[it.second] += 1;
        }
        for(int &num : nums){
            if(freqCount[mp[num]] == 1) return num;
        }
        return -1;
    }
};