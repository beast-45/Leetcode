class Solution {
public:
    int reverse(int x) {
        int rn = 0;
        while(x != 0){
            int ld = x%10;
            if(rn > INT_MAX/10 || rn<INT_MIN/10)
                return 0;
            rn = (rn*10)+ld;
            x /= 10;
        }
        return rn;
    }
};