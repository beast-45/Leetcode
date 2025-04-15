class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string result = "";
        while(n>0){
            n--;
            result += n%26 + 'A';
            n /= 26;
        }
        reverse(begin(result),end(result));
        return result;
    }
};