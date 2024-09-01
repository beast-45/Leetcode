class Solution {
public:
    bool allchars(string &s)
    {
        for(char & ch : s)
        {
            if(ch>='a' && ch<='z') return true;
        }
        return false;
    }
    int maximumValue(vector<string>& strs) {
        int n = strs.size();
        int currlen = 0;
        int maxlen = 0;
        
        for(int i=0; i<n ; i++)
        {
            string cs = strs[i];
            if(allchars(cs)==true)
            {
                currlen = cs.length();
                maxlen = max(maxlen , currlen);
            }
            else
            {
                currlen =  stoi(cs);
                maxlen  = max(maxlen , currlen);
            }
        }
        return maxlen;
        
    }
};