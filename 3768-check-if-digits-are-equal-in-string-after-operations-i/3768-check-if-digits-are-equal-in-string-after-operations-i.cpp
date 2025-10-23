class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2){
            string str = "";
            for(int i=0 ; i<s.length()-1 ; i++){
                int num = ((s[i]-'0')+(s[i+1]-'0'))%10;
                str += num+'0';
            }
            s = str;
        }
        return s[0] == s[1] ? true : false;
     }
};