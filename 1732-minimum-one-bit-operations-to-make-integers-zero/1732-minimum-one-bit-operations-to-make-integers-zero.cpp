class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) return 0;
        vector<int> op(31,0);
        op[0] = 1;
        for(int i=1 ; i<31 ; i++){
            op[i] = 2*op[i-1]+1;
        }
        int result = 0;
        bool sign = true;
        for(int i=0 ; i<31 ; i++){
            int ithBit = ((1<<i)&n);
            if(ithBit == 0) continue;
            result += sign ? op[i] : -op[i];
            sign = !sign;
        }
        return abs(result);
    }
};