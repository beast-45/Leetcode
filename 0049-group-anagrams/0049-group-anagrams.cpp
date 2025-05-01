class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto &s : strs){
            string leader = s;
            sort(begin(leader),end(leader));
            mp[leader].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};