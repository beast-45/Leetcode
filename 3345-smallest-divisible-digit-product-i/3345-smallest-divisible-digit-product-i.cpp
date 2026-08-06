class Solution {
public:
    int digProd(int n){
        int prod = 1;
        while(n){
            prod *= n%10;
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while(1){
            if(digProd(n) % t == 0) return n;
            n += 1;
        }
        return -1;
    }
};