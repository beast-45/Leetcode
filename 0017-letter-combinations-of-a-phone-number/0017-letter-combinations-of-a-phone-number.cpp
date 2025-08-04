class Solution {
public:
    void solve(int index , int n , string &digits , string &temp , vector<string> &result , unordered_map<char,string> &mp){
        if(index >= n){
            result.push_back(temp);
            return;
        }
        char digit = digits[index];
        string s = mp[digit];
        for(int i=0 ; i<s.size() ; i++){
            temp += s[i];
            solve(index+1,n,digits,temp,result,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> result;
        if(n == 0) return result;
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
        solve(0,n,digits,temp,result,mp);
        return result;
    }
};