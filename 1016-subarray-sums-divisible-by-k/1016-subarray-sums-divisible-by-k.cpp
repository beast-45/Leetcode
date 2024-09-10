class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int subNum = 0;

        int sum = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (rem < 0)
                rem += k;
            if (mp.find(rem) != mp.end())
                subNum += mp[rem];
            mp[rem] += 1;
        }
        return subNum;
    }
};