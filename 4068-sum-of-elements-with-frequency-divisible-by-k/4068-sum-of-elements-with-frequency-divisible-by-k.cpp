class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int &num : nums){
            mp[num]++;
        }
        int result = 0;
        for(auto &it : mp){
            if(it.second % k == 0) result += (it.first*it.second);
        }
        return result;
    }
};