class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long divi = abs((long long)dividend);
        long long add = abs((long long)divisor); 
        long long count = 0;
        while (divi >= add) {
            long long d = add;  
            long long multiple = 1;
            while (divi >= (d + d)) {
                d += d;
                multiple += multiple;
            }
            divi -= d;
            count += multiple;
        }
        return (dividend < 0) != (divisor < 0) ? -count : count;
    }
};