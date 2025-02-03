class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < n) {
            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }
            mp[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};