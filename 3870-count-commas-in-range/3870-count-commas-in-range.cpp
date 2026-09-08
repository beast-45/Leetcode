class Solution {
public:
    int countCommas(int n) {
       return (n>999) ? n-999 : 0; 
    }
};