class Solution {
public:
    int minBitFlips(int start, int goal) {
        int afterManipulation = start^goal;
        return __builtin_popcount(afterManipulation);
    }
};