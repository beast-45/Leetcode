class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n % 2 != 0) return false;

        stack<int> fixed;
        stack<int> flex;

        for(int i=0 ; i<n ; i++){
            if(locked[i] == '0') flex.push(i);
            else if(s[i] == '(') fixed.push(i);
            else if(s[i] == ')')
            {
                if(!fixed.empty()) fixed.pop();
                else if(!flex.empty()) flex.pop();
                else return false;
            }
        }

        while(!fixed.empty() && !flex.empty() && fixed.top() < flex.top())
        {
            fixed.pop();
            flex.pop();
        }

        return fixed.empty();
    }
};