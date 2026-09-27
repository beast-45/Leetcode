class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> skipLength;
        string result = "";
        for(char ch : s){
            if(ch == '('){
                skipLength.push(result.length());
            }else if(ch == ')'){
                int l = skipLength.top();
                skipLength.pop();
                reverse(begin(result)+l,end(result));
            }else{
                result += ch;
            }
        }
        return result;
        
    }
};