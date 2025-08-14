class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.length() , j = 0;
        vector<string> rows(numRows);
        bool down = true;
        for(int i=0 ; i<n ; i++){
            rows[j].push_back(s[i]);
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
        string zigzag = "";
        for(int i=0 ; i<numRows ; i++){
            zigzag += rows[i];
        }
        return zigzag;
    }
};