class Solution {
public:
    string addOperation(string s , int a){
        for(int i=0 ; i<s.length() ; i++){
            if(i % 2 == 1){
                int num = s[i]-'0';
                num = (num+a)%10;
                s[i] = num + '0';
            } 
        }
        return s;
    }
    string rotateOperation(string s , int b){
        int n = s.length();
        b %= n;
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+b);
        reverse(begin(s)+b,end(s));
        return s;
    }
    string findLexSmallestString(string s, int a, int b) {
        int n = s.length();
        unordered_set<string> st;
        queue<string> q;
        q.push(s);
        string smallest = s;
        while(!q.empty()){
            string temp = q.front();
            q.pop();
            if(st.count(temp)) continue;
            st.insert(temp);
            smallest = min(temp,smallest);
            string opAdd = addOperation(temp,a);
            string opRotate = rotateOperation(temp,b);
            if(!st.count(opAdd)) q.push(opAdd);
            if(!st.count(opRotate)) q.push(opRotate);
        }
        return smallest;
    }
};