class Solution {
public:
    bool doesAliceWin(string s) {
        int vowels = 0;
        unordered_set<char> st{'a','e','i','o','u'};
        for(char &ch : s){
            if(st.count(ch)) vowels += 1;
        }
        return vowels == 0 ? false : true;
    }
};