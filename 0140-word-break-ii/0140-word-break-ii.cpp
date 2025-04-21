class Solution {
public:
    void solve(int index , string &s , string temp , unordered_set<string> &wordD , vector<string> &result){
        if(index == s.length()){
            temp.pop_back();
            result.push_back(temp);
            return;
        }
        for(int len=1 ; index+len<=s.length() ; len++){
            string t = s.substr(index,len);
            if(wordD.count(t)){
                solve(index+len,s,temp+t+" ",wordD,result);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        unordered_set<string> wordD(begin(wordDict),end(wordDict));
        string temp = "";
        solve(0,s,temp,wordD,result);
        return result;
    }
};