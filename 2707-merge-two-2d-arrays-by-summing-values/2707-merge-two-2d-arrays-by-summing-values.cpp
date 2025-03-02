class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;
        vector<vector<int>> result;
        for(auto &p : nums1){
            int id = p[0];
            int num = p[1];
            mp[id] += num;
        }
        for(auto &p : nums2){
            int id = p[0];
            int num = p[1];
            mp[id] += num;
        }
        for(auto it : mp){
            vector<int> t;
            t.push_back(it.first);
            t.push_back(it.second);
            result.push_back(t);
        }
        return result;
    }
};