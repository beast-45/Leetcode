class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string , int>mp;
        vector<string> result;
        string temp = "";

        for(char &ch : s1)
        {
            if(ch==' ')
            {
                mp[temp]++;
                temp = "";
            }
            else temp += ch;
        }
        if(!temp.empty()) mp[temp]++;
        temp = "";
        for(char &ch : s2)
        {
            if(ch == ' ')
            {
                mp[temp]++;
                temp = "";
            }
            else temp += ch;
        }
        if(!temp.empty()) mp[temp]++;


        for(auto &it : mp)
        {
            if(it.second == 1) result.push_back(it.first);
        }
        return result;
        
    }
};