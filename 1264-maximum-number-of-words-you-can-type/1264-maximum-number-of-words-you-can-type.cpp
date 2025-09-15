class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(char &ch : brokenLetters){
            st.insert(ch);
        }
        int count = 0;
        for(int i=0 ; i<text.size() ; i++){
            bool completeWord = true;
            while(i<text.size() && text[i] != ' '){
                if(st.find(text[i]) != st.end()) completeWord = false;
                i++;
            }
            if(completeWord) count += 1;
        }
        return count;
    }
};