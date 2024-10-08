class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;

        for(char &ch : s)
        {
            if(ch == '[') st.push(ch);
            else if(st.size() > 0) st.pop();
        }
        
        return (st.size()+1)/2;
    }
};