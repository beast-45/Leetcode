class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string &word : words)
        {
            string r = string(rbegin(word),rend(word));
            if(word == r) return word;
        }
        return "";
        
    }
};