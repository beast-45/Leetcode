class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sfreq(26);
        vector<int> tfreq(26);
        for (char& ch : s) {
            sfreq[ch - 'a']++;
        }
        for (char& ch : t) {
            tfreq[ch - 'a']++;
        }
        return sfreq == tfreq;
    }
};