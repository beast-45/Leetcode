class Solution {
public:
    int revN(int n){
        int temp = n;
        int revNum = 0;
        while(temp){
            revNum = (revNum)*10 + (temp%10);
            temp /= 10;
        }
        return n < 0 ? -revNum : revNum;

    }
    int mirrorDistance(int n) {
        int revNum = revN(n);
        return abs(n-revNum);
    }
};