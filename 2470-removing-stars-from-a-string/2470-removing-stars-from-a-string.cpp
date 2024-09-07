class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res = "";
        for(char & ch : s)
        {
            if(ch == '*') st.pop();
            else st.push(ch);
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(begin(res) , end(res));
        return res;
    }
};