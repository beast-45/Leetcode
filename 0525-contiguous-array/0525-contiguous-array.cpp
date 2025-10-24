class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int cs = 0 , maxLen = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i=0 ; i<n ; i++){
            cs += (nums[i] == 0) ? -1 : 1;
            if(mp.find(cs) != mp.end()){
                maxLen = max(maxLen,i-mp[cs]);
            }else{
                mp[cs] = i;
            }
        }
        return maxLen;
    }
};