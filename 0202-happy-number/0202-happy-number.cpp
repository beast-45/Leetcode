class Solution {
public:
    bool solve(int n , unordered_set<int> &st){
        if(n == 1) return true;
        if(st.find(n) != st.end()) return false;
        st.insert(n);
        int temp = 0;
        while(n){
            int ld = n%10;
            temp += ld*ld;
            n /= 10;
        }
        return solve(temp,st);
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        return solve(n,st);
    }
};