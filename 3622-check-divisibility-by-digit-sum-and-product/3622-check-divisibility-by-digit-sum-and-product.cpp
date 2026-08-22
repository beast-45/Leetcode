class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n , sum = 0 , product = 1;
        while(n){
            int ld = n%10;
            sum += ld;
            product *= ld;
            n /= 10;
        }
        return num%(sum+product) == 0;
    }
};