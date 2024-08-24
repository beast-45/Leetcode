class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &word : words)
        {
            if(word == string(rbegin(word),rend(word))) return word;
        }
        return "";
        
    }
};