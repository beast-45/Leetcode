class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length() , count = 1;
        for(int i=1 ; i<n ; i++){
            char curr = word[i];
            while(i<n && word[i-1] == word[i]){
                count += 1;
                i++;
            }
        }
        return count;
    } 
};