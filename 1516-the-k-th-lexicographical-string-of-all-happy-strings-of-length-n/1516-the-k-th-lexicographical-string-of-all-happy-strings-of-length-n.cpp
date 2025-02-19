class Solution {
public:
    void solve(int n , string &temp , int &k , int &count , string &result){
        if(temp.length() == n){
            count += 1;
            if(count == k){
                result = temp;
            }
            return;
        }
        for(char ch='a' ; ch<'d' ; ch++){
            if(!temp.empty() && temp.back() == ch){
                continue;
            }
            temp.push_back(ch);
            solve(n , temp , k , count , result);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<char> letters{'a' , 'b' , 'c'};
        string temp;
        string result = "";
        int count = 0;
        solve(n , temp , k  , count , result);
        return result;
    }
};