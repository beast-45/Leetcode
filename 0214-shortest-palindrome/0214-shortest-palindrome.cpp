class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        string rev =  s;
        reverse(begin(rev) ,end(rev));

        for(int i=0 ; i<n ; i++)
        {
            if(!memcmp(s.c_str() , rev.c_str() + i , n-i))
            {
                return rev.substr(0,i) + s;
            }
        }
        return rev + s;
    }
};