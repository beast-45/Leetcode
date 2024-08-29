class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int uniqcount = 0;
        unordered_map<int , int> mp;
        for(int &num : nums)
        {
            mp[num]++;
        }
        for(auto it : mp)
        {
            if(it.second == 1)
            {
                uniqcount += it.first;
            }
        }
        return uniqcount;
        
        
    }
};