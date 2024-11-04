class Solution {
public:
    string compressedString(string word) {
        int n = word.length();

        string result = "";
        int i=0;
        while(i<n)
        {
            int count = 0;
            char ch = word[i];
            while(i<n && count<9 && word[i] == ch)
            {
                count++;
                i++;
            }
            result += to_string(count) + ch;
        }
        return result;
        
    }
};