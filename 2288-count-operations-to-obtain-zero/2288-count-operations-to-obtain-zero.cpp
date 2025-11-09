class Solution {
public:
    int countOperations(int num1, int num2) {
        int ops = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                num1 -= num2;
                ops += 1;
                if (num1 == 0) return ops;
            } else {
                num2 -= num1;
                ops += 1;
                if (num2 == 0) return ops;
            }
        }
        return ops;
    }
};