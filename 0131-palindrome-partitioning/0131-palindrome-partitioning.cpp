class Solution {
public:
    bool isPlain(int start , int end , string &s){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index , string &s , vector<string> &temp , vector<vector<string>> &result){
        if(index == s.length()){
            result.push_back(temp);
            return;
        }
        for(int i=index ; i<s.length() ; i++){
            if(isPlain(index,i,s)){
                temp.push_back(s.substr(index,i-index+1));
                solve(i+1,s,temp,result);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> result;
        solve(0,s,temp,result);
        return result;
    }
};