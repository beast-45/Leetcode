class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> result;

        unordered_set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        vector<int> vString(n);
        string word = words[0];
        int s = word.size();
        if(st.find(word[0]) != st.end()  && st.find(word[s-1]) != st.end()) vString[0] = 1;
        else vString[0] = 0;

        for(int i=1 ; i<n ; i++)
        {
            string w = words[i];
            int s = w.size();
            if(st.find(w[0]) != st.end()  && st.find(w[s-1]) != st.end())
            {
                vString[i] = vString[i-1] + 1;
            }
            else 
            {
                vString[i] = vString[i-1];
            }
        }
        
        for(auto query : queries)
        {
            int l = query[0];
            int r = query[1];
            if(l > 0)result.push_back(vString[r] - vString[l-1]);
            else result.push_back(vString[r]);
        }
        return result; 
    }
};