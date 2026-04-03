class Solution {
public:
    int firstMatchingIndex(string s) {
        int n = s.length();
        int i = 0 , j = n-1;
        while(i<=j){
            if(s[i] == s[j-i]) return i;
            i++;
        }
        return -1;
    }
};