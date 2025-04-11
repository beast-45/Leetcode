class Solution {
public:
    int n;
    void solve(int index , string &temp , vector<string> &result , unordered_map<char,string> &mp , string &digits){
        if(index >= n){
            result.push_back(temp);
            return;
        }
        char ch = digits[index];
        string s = mp[ch];
        for(int i=0 ; i<s.length() ; i++){
            temp += s[i];
            solve(index+1,temp,result,mp,digits);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        vector<string> result;
        if(n == 0){
            return result;
        }
        string temp = "";
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(0,temp,result,mp,digits);
        return result;
    }
};