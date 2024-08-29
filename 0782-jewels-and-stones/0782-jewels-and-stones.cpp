class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        int j=0;
        for(char &ch : jewels)
        {
            st.insert(ch);
        }
        for(char &c : stones)
        {
            if(st.find(c) != st.end()) j++;
        }
        return j;
        
    }
};