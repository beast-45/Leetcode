class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, long long> mp;
        for(int &num : nums1)
        {
            mp[num] += m; 
        }
        for(int &num : nums2)
        {
            mp[num] += n;
        }

        int x = 0;
        for(auto &it : mp)
        {
            if(it.second % 2 != 0) x^= it.first;
        }
        return x;
    }
};