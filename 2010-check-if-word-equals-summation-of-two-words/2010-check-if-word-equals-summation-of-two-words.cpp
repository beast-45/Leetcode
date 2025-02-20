class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        for (char& ch : firstWord) {
            num1 = num1 * 10 + (ch - 'a');
        }
        for (char& ch : secondWord) {
            num2 = num2 * 10 + (ch - 'a');
        }
        for (char& ch : targetWord) {
            num3 = num3 * 10 + (ch - 'a');
        }
        int sum = num1 + num2;
        return sum == num3;
    }
};