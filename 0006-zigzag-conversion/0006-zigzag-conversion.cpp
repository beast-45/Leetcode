class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.length();
        bool down = true;
        vector<string> words(numRows);
        int j = 0;
        for(int i=0 ; i<n ; i++){
            words[j].push_back(s[i]);
            if(down){
                if(j == numRows-1){
                    down = false;
                    j--;
                }else{
                    j++;
                }
            }else{
                if(j == 0){
                    down = true;
                    j++;
                }else{
                    j--;
                }
            }
        }
        string result = "";
        for(string &word : words){
            result += word;
        }
        return result;
        
    }
};