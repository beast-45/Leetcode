class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int closed = 0;
        for(char &ch : s)
        {
            if(ch == '(') closed++;
            else if(closed > 0) closed--;
            else open++;
        }
        return open + closed;
    }
};