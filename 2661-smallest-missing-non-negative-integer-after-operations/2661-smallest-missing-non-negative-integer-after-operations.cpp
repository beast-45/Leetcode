class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int &num : nums){
            int m = ((num%value)+value)%value;
            mp[m]++;
        }
        int mex = 0;
        while(mp.find(mex%value) != mp.end() && mp[mex%value] > 0){
            mp[mex%value]--;
            mex++;
        }
        return mex;
    }
};