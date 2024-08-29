class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i= 0;
        int j= 0;
        for(int k=0 ; k<=n ; k++)
        {
            if(s[k]==' ' || k==n)
            {
                j=k;
                reverse(s.begin()+i , s.begin()+j);
                i=k+1;
            } 

        }
        return s;
        
    }
};