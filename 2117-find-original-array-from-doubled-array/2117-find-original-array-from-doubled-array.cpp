class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        unordered_map<int,int> mp;
        vector<int> result;

        if(n%2 != 0) return {};

        sort(begin(changed) , end(changed));
        
        for(int &num : changed)
        {
            mp[num]++;
        }

        for(int &num : changed)
        {
            int twice = 2*num;
            if(mp[num]==0) continue;
            if(mp.find(twice) == mp.end() || mp[twice]==0)
            {
                return {};
            }
            result.push_back(num);
            mp[twice]--;
            mp[num]--;
        }
        return result;
    }
};