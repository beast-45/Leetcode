class Solution {
public:
    string smallestString(string s) {
        int n = s.length() , index = 0;
        while(index < n && s[index] == 'a') index++;
        if(index == n){
            s.pop_back();
            s += 'z';
            return s;
        }
        while(index <n && s[index] != 'a'){
            s[index] = s[index]-1;
            index++;
        }
        return s;
    }
};