class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // int m = words.size();
        // int n = s.length();
        // if (m != n) return false;
        string acr = "";
        for(string & word : words)
        {
            acr.push_back(word[0]);
        }
        if(acr == s) return true;
        return false;
    }
};