class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0 , j = 0 , maxLen = 0;
        unordered_map<char,int> mp;
        while(j<n){
            if(mp.find(s[j]) != mp.end() && mp[s[j]] >= i){
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};