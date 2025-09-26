class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n % 2 != 0)
            return false;
        stack<char> st;
        for (char& ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) return false;
                else if ((ch == ')' && st.top() != '(') || (ch == ']' && st.top() != '[') || (ch == '}' && st.top() != '{')){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
