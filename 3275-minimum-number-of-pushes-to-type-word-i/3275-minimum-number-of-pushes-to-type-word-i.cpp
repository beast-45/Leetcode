class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length(); 
        if(word.length()<=8) return word.length();
        if(word.length()>8 && word.length()<=16)
        {
            return 8 + (n-8)*2;
        }
        if(word.length()>16 && word.length()<=24)
        {
            return 8 + 16 + (n-16)*3;
        }
        if(word.length()>24)
        {
            return 8 + 16 + 24 +(n-24)*4;
        }
        return 0;
        
    }
};