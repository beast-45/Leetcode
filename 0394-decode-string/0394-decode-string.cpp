class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<int> iStack;
        stack<string> sStack;
        string result = "";
        int num = 0;
        string curr = "";
        for(int i=0 ; i<n ; i++){
            char ch = s[i];
            if(isdigit(ch)){
                num = num*10 + (ch-'0');
            }
            else if(ch == '['){
                iStack.push(num);
                sStack.push(curr);
                num = 0;
                curr = "";
            }
            else if(ch == ']'){
                int reps = iStack.top();
                iStack.pop();
                string repStr = sStack.top();
                sStack.pop();
                string temp = "";
                for(int i=0 ; i<reps ; i++){
                    temp += curr;
                }
                curr = repStr + temp;
            }
            else{
                curr += ch;
            }
        }
        return curr;
    }
};