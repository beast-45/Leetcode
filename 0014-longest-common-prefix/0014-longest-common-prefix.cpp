class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string lcp = "";
        for(int i=0 ; i<strs[0].size() ; i++){
            char ch = strs[0][i];
            bool all = true;
            for(int j=1 ; j<n ; j++){
                if(strs[j][i] == ch) continue;
                else{
                    all = false;
                    break;
                }
            }
            if(all) lcp += ch;
            else break;
        }
        return lcp;
    }
};