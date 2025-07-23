class Solution {
public:
    int removeBoth(string &s , int value) {
        stack<char> st;
        int score = 0;
        for (char &ch : s){
            if(!st.empty()){
                char top = st.top();
                if ((top == 'a' && ch == 'b') || (top == 'b' && ch == 'a')) {
                    st.pop();
                    score += value;
                    continue;
                }
            }
            st.push(ch);
        }
        return score;
    }
    string removeMString(string &s , string &maxs){
        stack<char> st;
        for(int i=0 ; i<s.length() ; i++){
            if(!st.empty() && st.top() == maxs[0] && s[i] == maxs[1]) st.pop();
            else st.push(s[i]);
        }
        string temp = "";
        while(!st.empty()){
            temp += st.top();
            st.pop();
        }
        reverse(begin(temp),end(temp));
        return temp;
    }
    int maximumGain(string s, int x, int y) {
        if (x == y) return removeBoth(s, x);
        int n = s.length() , score = 0;
        string maxString = x > y ? "ab" : "ba";
        string minString = x < y ? "ab" : "ba";
        string temp = removeMString(s,maxString);
        int removed = n-temp.length();
        score += (removed/2)*max(x,y);
        string temp2 = removeMString(temp,minString);
        removed = temp.length()-temp2.length();
        score += (removed/2)*min(x,y);
        return score;
    }
};