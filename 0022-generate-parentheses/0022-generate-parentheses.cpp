class Solution {
public:
    void solve(int open , int close , string temp , vector<string> &result , int n){
        if(temp.length() == 2*n){
            result.push_back(temp);
            return;
        }
        if(open < n){
            solve(open+1,close,temp+'(',result,n);
        }
        if(open > close){
            solve(open,close+1,temp+')',result,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(0,0,"",result,n);
        return result;
    }
};