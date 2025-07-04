class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        int length = 1;
        while(s.length() <= k){
            string temp = "";
            for(auto ch : s){
                temp += (ch == 'z') ? 'a' : ch+1; 
            }
            s += temp;
        }
        return s[k-1];
    }
};