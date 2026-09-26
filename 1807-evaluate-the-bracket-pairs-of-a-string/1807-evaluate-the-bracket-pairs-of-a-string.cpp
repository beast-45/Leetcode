class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string,string> mp;
        for(auto &k : knowledge){
            mp[k[0]] = k[1];
        }
        int i = 0;
        string result = "";
        while(i<n){
            if(s[i] == '('){
                int j = i+1;
                string key = "";
                while(j<n && s[j] != ')'){
                    key += s[j];
                    j++;
                }
                if(mp.find(key) != mp.end()){
                    result += mp[key];
                }else{
                    result += "?";
                }
                i = j;
            }else{
                result += s[i];
            }
            i++;
        }
        return result;
    }
};