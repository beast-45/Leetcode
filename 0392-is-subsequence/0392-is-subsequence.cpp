class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length() , n = t.length() , i = 0 , j = 0;
        while(j < n){
            if(s[i] == t[j]){
                i += 1;
            }
            j++;
        }
        return i == m;
    }
};