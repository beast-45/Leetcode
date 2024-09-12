class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = words.size();

        int na = 0;
        unordered_map<char,int> mp;
        for(char &ch : allowed)
        {
            mp[ch]++;
        }
        for(string &word : words)
        {
            for(char &ch : word)
            {
                if(mp.find(ch) == mp.end())
                {
                    na += 1;
                    break;
                }
            }
        }

        return n-na;
        
    }
};