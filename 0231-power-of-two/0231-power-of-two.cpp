class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        int setBits = __builtin_popcount(n);
        return setBits == 1;
    }
};