class Solution {
public:
    void solve(int n , string &temp , vector<string> &happyStrings , vector<char> &letters){
        if(temp.length() == n){
            happyStrings.push_back(temp);
            return;
        }
        for(int i=0 ; i<3 ; i++){
            if(!temp.empty() && temp.back() == letters[i]){
                continue;
            }
            temp.push_back(letters[i]);
            solve(n , temp , happyStrings , letters);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<char> letters{'a' , 'b' , 'c'};
        string temp;
        vector<string> happyStrings;
        solve(n , temp , happyStrings , letters);
        if(k>happyStrings.size()){
            return "";
        }
        return happyStrings[k-1];
    }
};