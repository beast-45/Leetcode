class Solution {
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i=0 ; i<n-1 ; i++){
            int num1 = s[i]-'0';
            int num2 = s[i+1]-'0';
            if(num1%2 == num2%2 && num1 > num2){
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};