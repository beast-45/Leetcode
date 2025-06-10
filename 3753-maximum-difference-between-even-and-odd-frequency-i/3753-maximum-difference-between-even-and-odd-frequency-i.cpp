class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char &ch : s){
            mp[ch]++;
        }
        vector<int> e;
        vector<int> o;
        for(auto &it : mp){
            if(it.second % 2 == 0){
                e.push_back(it.second);
            }
            else{
                o.push_back(it.second);
            }
        }
        if(e.empty() || o.empty()){
            return 0;
        }
        int maxo = *max_element(begin(o) , end(o));
        int mine = *min_element(begin(e) , end(e));
        return maxo-mine; 
    }
};