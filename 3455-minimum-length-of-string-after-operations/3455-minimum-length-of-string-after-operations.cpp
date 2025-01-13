class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        int minLength = 0;
        for(char &ch : s)
        {
            mp[ch] += 1;
            if(mp[ch] >= 3) mp[ch] -= 2;
        }
        for(auto &iterator : mp)
        {
            minLength += iterator.second;
        }
        return minLength; 
    }
};