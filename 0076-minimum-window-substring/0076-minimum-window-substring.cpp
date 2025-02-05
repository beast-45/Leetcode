class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length() > s.length()){
            return "";
        }
        unordered_map<char,int> mp;
        for(char &ch : t){
            mp[ch] += 1;
        }
        int reqCount = t.size();
        int i = 0;
        int j = 0;
        int minWinSize = INT_MAX;
        int startIndex = 0;

        while(j<n){
            char ch = s[j];
            if(mp[ch] > 0){
                reqCount -= 1;
            }
            mp[ch]--;
            while(reqCount == 0){
                int currWinSize = j-i+1;
                if(minWinSize > currWinSize){
                    minWinSize = currWinSize;
                    startIndex = i;
                }
                mp[s[i]] += 1;
                if(mp[s[i]] > 0){
                    reqCount += 1;
                }
                i++;
            }
            j++;
        }
        return minWinSize == INT_MAX ? "" : s.substr(startIndex , minWinSize); 
    }
};